/*
 * VGA console header file
 * console.h
 *
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

#ifndef __CONSOLE_H__
#define __CONSOLE_H__

// #include <stdbool.h>
// #include <stddef.h>
// #include <stdint.h>

namespace Console
{
	// Encapsulate low-level VGA functions
	namespace
	{
		void GetPosition();							// Return cursor position
		void PutChar(char c, size_t position);		// Print char to screen
	}

    // functions that can be called from the kernel
	void Println(const char* data);					// Classic print function
	void Clear();								// Clear screen
};


#endif