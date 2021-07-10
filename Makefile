# Makefile

AS=as
CC=clang
CXX=clang++
LD=/usr/local/bin/ld

ASFLAGS=	-march=i686 --32

CFLAGS=		-c -march=i686 -target i386-none-elf -std=gnu99 \
			-ffreestanding -O2 -Wall -Wextra

CXXFLAGS=	-c -march=i686 -target i386-none-elf -ffreestanding \
			-O2 -Wall -Wextra -fno-exceptions -fno-rtti

LDFLAGS=	-melf_i386 -nostdlib -v


.PHONY : all clean dbgkern
all:
	$(AS) $(ASFLAGS) boot.s -o boot.o 
	$(CXX) $(CXXFLAGS) kernel.cc -o kernel.o
	$(CXX) $(CXXFLAGS) console.cc -o console.o
	$(LD) $(LDFLAGS) -T linker.ld -o kernel  boot.o kernel.o console.o

clean:
	rm *.o kernel

dbgkern:
	qemu-system-i386 -kernel kernel