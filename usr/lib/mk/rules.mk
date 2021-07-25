#
# This file is a part of Chimera
#
# Copyright (c) 2021
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
# along with this program.  If not, see <https://www.gnu.org/licenses/>.


# In a nutshell, the %.o : %.* targets want to create '.o' files out of '.xyz'
# files. To utilize these convenient functions however, you need to have
# a target that depends on .o files. It would be very difficult to scale
# a project that required the devs to write 'xyz.o' to a list inside of the
# makefile everytime they added source. For this reason, we create two variables
# that find every file in the current directory with a given extension, then 
# flip the extension to '.o'. This allows us to simply create a makefile in any
# new directory, import THIS '.mk' file, and all of the source will be built.
# Obviously, you will need to include other '.mk' files in order to pass the
# proper flags to the build tools.


#Tell make how to assemble .s files into .o files
%.o : %.s
	@printf 'AS\t%s\n' $<
	@$(AS) $(ASFLAGS) $< -o $@

# Tell make how to compile .cc files into .o files
%.o : %.cc
	@printf 'CXX\t%s\n' $<
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@