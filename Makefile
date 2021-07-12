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

#include Makefile.conf

# [NOTE]
# If you get a weird error from Make, ensure that there are only
# tabs used to indent the commands inside of targets. Make whitespace
# is not as lenient as C/C++ whitespace.

# Tells make not to try and create files from these targets
.PHONY : all clean buildkernel buildworld release dbgkern

# Default target for make
all:
	@echo "Building 'all' is not recommended."
	@echo "Try 'make buildkernel'"


buildkernel:
	@echo #"Building kernel."

	@echo #"Built kernel."

	@echo "Linking kernel."
	$(LD) $(LDFLAGS) -T $(LDSCRIPT) -o kernel $(OBJ_DIR)

buildworld: # buildkernel
	@echo "Not defined yet. This will build all userspace apps and libs"

# Target to clean up the tree. This deletes all of the object files
# and the kernel executable
clean:
	rm -fv *.o
	rm -fv kernel

release: # buildkernel buildworld ?
	@echo "Not defined yet. This call will create a bootable image and output .tar files"

# Starts qemu with the '-kernel' flag so we can boot our kernel without a bootloader
# TODO: Have it load qemu in debug mode to allow us to step through the kernel. It should
#			also depend on the buildkernel target.
dbgkern:
	qemu-system-i386 -kernel kernel


include Makefile.conf


#	assemble entry code
#	#@echo [AS] entry.s
#	#@$(AS) $(ASFLAGS) sys/arch/i386/entry.s -o entry.o
#
#	#compile sources using clang++
#	#@echo [CXX] console.cc
#	#@$(CXX) $(CXXFLAGS) -I $(INCL) -c sys/core/console/console.cc -o console.o
#
#	#@echo [CXX] kmain.cc
#	#@$(CXX) $(CXXFLAGS) -I $(INCL) -c sys/core/kmain.cc -o kmain.o
#
#	#@echo [CXX] iobus.cc
#	#@$(CXX) $(CXXFLAGS) -I $(INCL) -c sys/arch/i386/drivers/iobus/iobus.cc -o iobus.o
#
#	#@echo [CXX] vga.cc
#	#@$(CXX) $(CXXFLAGS) -I $(INCL) -c sys/arch/i386/drivers/vga/vga.cc -o vga.o
#
#	#  Link kernel object files into elf binary
#	# @echo [LD] kernel
#	# @$(LD) $(LDFLAGS) -T $(LDSCRIPT) -o kernel entry.o kmain.o console.o vga.o