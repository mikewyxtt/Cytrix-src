#
# This file is a part of <OS>
#
# Copyright (c) 2021
# Michael Wyatt, All rights reserved.
#
# This file contains code from:
# Michael Wyatt
#
# <OS> is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# <OS> is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.



# [NOTE]
# If you get a weird error from Make, ensure that there are only
# tabs used to indent the commands inside of targets. Make whitespace
# is not as lenient as C/C++ whitespace.

# tell make what build tools we wanna use
AS=as
CC=clang
CXX=clang++
LD=/usr/local/bin/ld
TARGET_ARCH=i386

# tell gnu assembler what flags we want to use while compiling
ASFLAGS=	-march=i686 --32

# tell clang (C version) what flags we want to use
CFLAGS=		--march=i686 -target i386-none-elf -std=gnu99 \
			-ffreestanding -O2 -Wall -Wextra

# tell clang (C++ version) what flags we want to use
CXXFLAGS=	-march=i686 -target i386-none-elf -ffreestanding \
			-O2 -Wall -Wextra -fno-exceptions -fno-rtti \
			-DTARGET_ARCH=$(TARGET_ARCH)
			# -nostdinc -nostdlibinc -nobuiltininc ?

# tell the gnu linker what flags we want to use at link-time
LDFLAGS=	-melf_i386 -nostdlib -v

# tell clang where we put our include files
INCL=sys/include

# tell make location of linker script
LDSCRIPT=sys/arch/i386/linker.ld


# tells make not to try and create files from these targets
.PHONY : all clean dbgkern buildkernel

# default target for make
all: buildkernel


buildkernel:
	@echo "Building kernel."

	# assemble entry code
	@echo [AS] entry.s
	@$(AS) $(ASFLAGS) sys/arch/i386/entry.s -o entry.o

	#compile sources using clang++
	@echo [CXX] console.cc
	@$(CXX) $(CXXFLAGS) -I $(INCL) -c sys/core/console/console.cc -o console.o

	@echo [CXX] kmain.cc
	@$(CXX) $(CXXFLAGS) -I $(INCL) -c sys/core/kmain.cc -o kmain.o

	#@echo [CXX] iobus.cc
	#@$(CXX) $(CXXFLAGS) -I $(INCL) -c sys/arch/i386/drivers/iobus/iobus.cc -o iobus.o

	@echo [CXX] vga.cc
	@$(CXX) $(CXXFLAGS) -I $(INCL) -c sys/arch/i386/drivers/vga/vga.cc -o vga.o

	# Link kernel object files into elf binary
	@echo [LD] kernel
	@$(LD) $(LDFLAGS) -T $(LDSCRIPT) -o kernel entry.o kmain.o console.o vga.o

	@ echo "Built kernel."

# run 'make clean' to clean up the tree. this deletes all of the object files
# and the kernel executable
clean:
	rm *.o kernel

# opens qemu with the kernel flag so we can boot our kernel without a bootloader
dbgkern:
	qemu-system-i386 -kernel kernel