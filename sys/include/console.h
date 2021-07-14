/*
 * This file is a part of Cytrix
 * 
 * Copyright (c) 2021
 * Michael Wyatt, All rights reserved.
 *
 * This file contains code from:
 * Michael Wyatt
 *
 * Cytrix is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cytrix is distributed in the hope that it will be useful,
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

#include <kernel.h>

// TODO: create logic to determine architecture
#include <../arch/i386/drivers/vga/vga.h>

namespace Kernel
{
	class Console
	{
	public:
		static void Initialize();						// Initialize the console
		static void PutChar(char Char);					// Print char to screen
		static void Println(const char* data);			// Classic print function
		static void Clear();							// Clear screen

		class Cursor
		{
		public:
			static size_t GetPosition();				// Retrieve cursor pos from mem
			static void SetPosition(uint8_t X, uint8_t Y);	// Set cursor position
			static void Enable();
			static void Disable();
			size_t Position;
		};
		
		// VGA color map
		//enum Color;
	};
}

#endif