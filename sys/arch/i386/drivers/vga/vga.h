/*
 * This file is a part of <OS>
 * 
 * Copyright (c) 2021
 * Michael Wyatt, All rights reserved.
 *
 * This file contains code from:
 * Michael Wyatt
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

#ifndef __VGA_H__
#define __VGA_H__
#include <kernel.h>

namespace Kernel
{
	class VGA
	{
		/*
			Functions:
				static void PutChar() - Prints single character to video memory
		*/
	public:
		enum Color
		{
			Black = 0,
			Blue = 1,
			Green = 2,
			Cyan = 3,
			Red = 4,
			Magenta =	5,
			Brown = 6,
			Light_Grey = 7,
			Dark_Grey = 8,
			Light_Blue = 9,
			Light_Green = 10,
			Light_Cyan = 11,
			Light_Red = 12,
			Light_Magenta = 13,
			Light_Brown = 14,
			White = 15,
		};
		static /*inline*/ void PutChar(char Char,size_t Position, Color Foreground, Color Background);
		class Cursor
		{
			/*
			Functions:
				static void Enable(); // Enables text mode cursor
				static void Disable(); // Disables text mode cursor
				static uint16_t GetPosition(); // Returns position of text mode cursor
				static void SetPosition(uint8_t X, uint8_t Y); // Sets position of text mode cursor
			*/
		public:
			static void Enable();
			static void Disable();
			static size_t GetPosition();
			static void SetPosition(uint8_t X, uint8_t Y);
			uint16_t Position;
		};
	private:
		//uint16_t* Buffer;

	};
}

#endif