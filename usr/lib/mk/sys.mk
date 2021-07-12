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

# include $(PREFIX_DIR)/Makefile.conf $(PREFIX_DIR)/usr/lib/mk/generic.mk

# We are going to purposefully use the '=' assignment operator to
# override any include paths that were thrown in to prevent stdlib
# from being included

include $(PREFIX_DIR)/usr/lib/mk/generic.mk

## Standard, cross platform flags
#
# In a nutshell, we are telling not to include any standard libraries as we are
# running in a freestanding environment. This also means that we do not have
# exception handling nor do we have the ctti.o files to link against. This is
# subject to change, but without those function constructors are not called.
#
# It is important to note the use of the '+=' assignment operator: without it
# we would override all of the existing flags we set in other .mk includes as
# well as anything passed in from the terminal.
CXXFLAGS+=	-ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti \
			-DTARGET_ARCH=$(TARGET_ARCH) # -nostdinc -nostdlibinc \
			-nobuiltininc ?
LDFLAGS+=	-nostdlib

# Tell ld which linker script to use
LDSCRIPT=	$(PREFIX_DIR)/sys/arch/$(TARGET_ARCH)/link.ld

# Include kernel headers
INCLUDES=-I $(PREFIX_DIR)/sys/include

## Arch specific flags

# i386
ifeq ($(TARGET_ARCH),i386)
	ASFLAGS+=	-march=i686 --32
	CXXFLAGS+=	-march=i386 -target i386-none-elf
	LDFLAGS+=	-melf_i386 -nostdlib
endif

