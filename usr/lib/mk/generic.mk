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

# include $(PREFIX_DIR)/Makefile.conf
.PHONY: clean
# Tell make how to assemble .s files into .o files
entry.o : entry.s
	echo [AS] $<
	$(AS) $(ASFLAGS) entry.s -o entry.o

# Tell make how to compile .cc files into .o files
%.o : %.cc
	echo [CXX] $<
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

include $(PREFIX_DIR)/Makefile.conf
# clean:
# 	rm -fv *.o
# 	rm -fv kernel