/* yes - implementation of /bin/yes - public domain. */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
static char buf[8192];
static unsigned bufused;

/* append string to buffer */
static void addbuf(const char *s)
{
	unsigned n = strlen(s);
	memcpy(buf + bufused, s, n);
	bufused += n;
}

static void repbuf(void)
{
	unsigned n = bufused;
	/* copy - doubling each time */
	while (bufused * 2 < sizeof(buf)) {
		memcpy(buf + bufused, buf, bufused);
		bufused *= 2;
	}
	/* copy linearly */
	while (bufused + n < sizeof(buf)) {
		memcpy(buf + bufused, buf, n);
		bufused += n;
	}
}

static void loopbuf(void)
{
	while (1) {
		ssize_t written;
		unsigned total;
		for (total = 0; total < bufused; total += written) {
			written = write(STDOUT_FILENO, buf, bufused);
			if (written <= 0)
				return; /* error */
		}
	}
}

int main(int argc, char **argv)
{
	/* bufused = 0; * reset buffer position */
	if (argc == 1) {
		addbuf("y\n");
	} else {
		int i;
		for (i = 1; i < argc; i++) {
			addbuf(argv[i]);
			addbuf(i + 1 < argc ? " " : "\n");
		}
	}
	repbuf();
	loopbuf();
	perror(argv[0]);
	return 1;
}
