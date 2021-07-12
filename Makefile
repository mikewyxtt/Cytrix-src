#
# This file is a part of Cytrix
#
# Copyright (c) 2021
# Michael Wyatt, All rights reserved.
#
# This file contains code from:
# Michael Wyatt
#
# Cytrix is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Cytrix is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

# NOTE:
# 	If you get a weird error from make, ensure that there are only
#	tabs used for indentationinside of targets. Make whitespace is not 
#	ignored like C/C++ whitespace is.


include Makefile.conf
include $(PREFIX_DIR)/usr/lib/mk/sys.mk

# Tells make not to try and create files from these targets
.PHONY : all clean buildkernel buildworld release dbgkern $(SYS_SRC_DIRS)

# Default target for make
all:
	@echo "Building 'all' is not recommended. Supported make targets are:"
	@echo
	@echo "buildkernel buildworld installkernel installworld clean release dbgkern"
	@echo
	@echo "View README.md for more info."

# Compiles kernel sources and outputs the kernel executable
buildkernel: $(SYS_SRC_DIRS)
	@echo "Linking kernel."
	$(LD) $(LDFLAGS) -T $(LDSCRIPT) -o kernel $(OBJ_DIR)/*.o
	@echo "Kernel linked."

# Compiles the base system
buildworld:
	@echo "Not defined yet. This will build all userspace apps and libs"

# Target to clean up the tree. This deletes all object and executable files
clean:
	rm -fv $(OBJ_DIR)/*.o
	rm -fv kernel
	rm -Rfv $(OBJ_DIR)

# Create ISO image and create .tar.xz of source files
release: # buildkernel buildworld ?
	@echo "Not defined yet. This call will create a bootable ISO and output .tar.xz files for distribution"

# Starts qemu with the '-kernel' flag so we can boot our kernel without a bootloader
dbgkern:
	qemu-system-i386 -kernel kernel
	# TODO: Have it load qemu in debug mode to allow us to step through the kernel. It should
#			also depend on the buildkernel target.


## Back end targets to make the main targets work

# Dependency to target 'buildkernel'. Recursively runs make throughout kernel source dirs
$(SYS_SRC_DIRS):
	@mkdir -p $(OBJ_DIR)
	@echo "Building kernel."
	@$(MAKE) --directory=$@
	@echo "Built kernel."
