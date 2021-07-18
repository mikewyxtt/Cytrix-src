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
#ifndef __KERNEL_H__
#define __KERNEL_H__

// Compiler headers
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Headers from /sys/include
#include <core/console/console.h>
#include <panic.h>
#include <iobus.h>

// Check if the compiler thinks you are targeting the wrong operating system.
// #if !defined(__CYTRIX__)
// #error "Cytrix must be compiled with the Cytrix clang compiler. Run 'make xtools' in the source tree root to build the cross compiler"
// #endif
 
#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif

#endif