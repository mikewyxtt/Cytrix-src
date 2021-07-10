/*
 * This file is a part of <OS>
 * 
 * <OS> is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * <OS> is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
 
#include <console.h>

/* Check if the compiler thinks you are targeting the wrong operating system. */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif
 
/* This tutorial will only work for the 32-bit ix86 targets. */
#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif
 



extern "C" void kernel_main(void) 
{
	/* Initialize terminal interface */
//	Console::Clear();

//	Console::Println("Print here\n");
//	Console::Println("And here\n");
 
	/* Newline support is left as an exercise. */
//	terminal_writestring("OUTPUT FROM CLANG++ Without mangling!!! WITH OUR FIRST CLASS!! NOW WITH TWO FILES\n");
}