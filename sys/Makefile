#
# This file is a part of Chimera
#
# Copyright © 2021
# Michael Wyatt, All rights reserved.
#
# This file contains code from:
# Michael Wyatt
#
# Chimera is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Chimera is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <https://www.gnu.org/licenses/>.


include $(PREFIX_DIR)/Makefile.conf
include $(PREFIX_DIR)/usr/lib/mk/rules.mk
include ./Makefile.conf
include ./Makefile.inc1

.PHONY: clean all

# Target 'all' depends on the file 'kernel'. if it exists, make will quit in this
# directory. If it does not exist, make will compile the source code (./src.mk)
# into objects using the rules found in /usr/lib/mk/rules.mk

all: kernel

kernel: $(OBJS)
	@echo 'Linking kernel...'
	@$(LD) $(LDFLAGS) -T $(LDSCRIPT) -o kern/kernel $(OBJS)
	@echo 'Kernel linked.'

clean:
	@echo 'Cleaning kernel tree...'
	@rm -fv $(OBJS)
	@rm -fv kern/kernel
	@echo 'Cleaned kernel tree'
	
