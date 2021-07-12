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

# include $(PREFIX_DIR)/Makefile.conf $(PREFIX_DIR)/usr/lib/mk/generic.mk

# We are going to purposefully use the '=' assignment operator to
# override any include paths that were thrown in to prevent stdlib
# from being included
INCLUDES=-I $(PREFIX_DIR)/sys/include

# Flags for Clang++.
#
# In a nutshell, we tell clang not to include any standard libraries as we are
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
# Flags for ld
#
# Similar to our clang flags, we do not wish to link any (hosted) standard libs
# into our kernel.
LDFLAGS+=	-nostdlib

# Tell ld which linker script to use
LDSCIPT=	$(PREFIX_DIR)/sys/arch/$(TARGET_ARCH)/link.ld

#include $(PREFIX_DIR)/Makefile.conf $(PREFIX_DIR)/usr/lib/mk/generic.mk