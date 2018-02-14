# MIPS program examples

## Ownership, License and Copyright Information

    mips-tutorial - MIPS program examples

    Written in 2018 by Jon Mayo <jon.mayo@gmail.com>

    To the extent possible under law, the author(s) have dedicated all
    copyright and related and neighboring rights to this software to the public
    domain worldwide. This software is distributed without any warranty.

    You should have received a copy of the CC0 Public Domain Dedication along with
    this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.

## Programs

* true - returns true to the shell (0)
* false - returns false to the shell (1)
* hello - Prints "Hello World" message

## Setup: How to setup MIPS toolchain (gcc) on Ubuntu 14.04

### Step 1: Add  following to /etc/apt/sources.list

```
## add in Squeeze (Debian 6.0) and Emdebian
deb http://archive.debian.org/debian squeeze main
deb http://archive.debian.org/debian squeeze-lts main
deb http://www.emdebian.org/debian/ squeeze main
```

### Step 2: Update apt and instal keyrings

```
sudo apt-get update
sudo apt-get install debian-archive-keyring debian-ports-archive-keyring
sudo apt-get install emdebian-archive-keyring
```

### Step 3: Install MIPS tools

```
  apt-get install linux-libc-dev-mips-cross libc6-mips-cross \
      libc6-dev-mips-cross binutils-mips-linux-gnu \
      gcc-4.4-mips-linux-gnu g++-4.4-mips-linux-gnu
```

### Step 4: Check MIPS tools

  mips-linux-gnu-gcc -dumpmachine

### Step 5: Install qemu tools (optional)

  sudo apt-get install qemu qemu-system-mips qemu-user

### Step 6: Install MIPS simulators (optional)

The classic option is SPIM, but it has some syntax limiations that makes it hard to use the output of gcc directly.
```
  sudo apt-get install spim
```

Another option is drmips. (I haven't done much with it myself)
```
  sudo apt-get install drmips
```

## Building

You should be able to type `make` and get some MIPS binaries out. You can edit the *Makefile* if you need to change the tool names or paths.

## Running

The Hello World program:
```
qemu-mips ./hello
```

The True/False programs
```
qemu-mips ./true ; echo $?
qemu-mips ./false; echo $?
```

## Contributing

Send a pull request via Github.com, or send e-mails containing patches.
