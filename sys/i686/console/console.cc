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

// #include <stdbool.h>
// #include <stddef.h>
// #include <stdint.h>

#include <console.h>

// Low level VGA functions

Console::GetPosition()
{
	// Get the cursor position from vga mem
	// return cursor position
}

Console::PutChar(char c, size_t position)
{
	// print char to screen
}

// Functions accessible to kmain

Console::Println(const char* data)
{
	// print text to screen

//	for(size_t i = 0; i < sizeof(data); i++)			// go through each char and print
//		PutChar(data[i], GetPosition());
}

Console::Clear()
{
	// Clear all fonts from vram and reset cursor
}