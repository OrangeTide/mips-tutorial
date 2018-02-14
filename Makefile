## Toolchain configuration
CC = mips-linux-gnu-gcc
LD = mips-linux-gnu-ld
AS = mips-linux-gnu-as
AR = mips-linux-gnu-ar

## Options
CFLAGS = -Wall -W -O1 -std=c99 -pedantic
LDFLAGS = -static

## Targets
all :: false.s false true.s true hello.s hello yes.s yes
clean :: ; $(RM) false.s false true.s true hello.s hello yes.s yes

## Pattern Rules
%.s : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -S -o $@ $<
