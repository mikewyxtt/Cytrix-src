# Makefile

# tell make what build tools we wanna use
AS=as
CC=clang
CXX=clang++
LD=/usr/local/bin/ld

# tell gnu assembler what flags we want to use while compiling
ASFLAGS=	-march=i686 --32

# tell clang (C version) what flags we want to use
CFLAGS=		--march=i686 -target i386-none-elf -std=gnu99 \
			-ffreestanding -O2 -Wall -Wextra

# tell clang (C++ version) what flags we want to use
CXXFLAGS=	-march=i686 -target i386-none-elf -ffreestanding \
			-O2 -Wall -Wextra -fno-exceptions -fno-rtti
			# -nostdinc -nostdlibinc -nobuiltininc ?

# tell the gnu linker what flags we want to use at link-time
LDFLAGS=	-melf_i386 -nostdlib -v

# tell clang where we put our include files
INCL=sys/include

# tell make location of linker script
LDSCRIPT=	sys/i686/linker.ld


# tells make not to try and create files from these targets
.PHONY : all clean dbgkern

# default target for make
all:
	# assemble entry code
	$(AS) $(ASFLAGS) sys/i686/entry.s -o entry.o

	#compile sources using clang++
	$(CXX) $(CXXFLAGS) -I $(INCL) -c sys/i686/console.cc -o console.o
	$(CXX) $(CXXFLAGS) -I $(INCL) -c sys/kern/kmain.cc -o kmain.o

	# Link kernel object files into elf binary
	$(LD) $(LDFLAGS) -T $(LDSCRIPT) -o kernel  entry.o kmain.o console.o

# run 'make clean' to clean up the tree. this deletes all of the object files
# and the kernel executable
clean:
	rm *.o kernel

# opens qemu with the kernel flag so we can boot our kernel without a bootloader
dbgkern:
	qemu-system-i386 -kernel kernel