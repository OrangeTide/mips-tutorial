## Toolchain configuration
CC = mips-linux-gnu-gcc
LD = mips-linux-gnu-ld
AS = mips-linux-gnu-as
AR = mips-linux-gnu-ar


##
CFLAGS += -Wall -W -std=c99 -pedantic -static
all :: false true hello
clean :: ; $(RM) false true hello
