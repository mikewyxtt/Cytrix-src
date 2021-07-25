/*
 * This file is a part of Chimera
 * 
 * Copyright © 2021
 * Michael Wyatt, All rights reserved.
 *
 * This file contains code from:
 * Michael Wyatt
 *
 * Chimera is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Chimera is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include <kernel.h>
#include "vga.h"
using namespace Kernel;
/*
namespace vga
{
class VGA
		{
		private:
			static uint16_t getCursorPosition()
			{
				uint16_t pos = 0;
				outb(0x3D4, 0x0F);
				pos |= inb(0x3D5);
				outb(0x3D4, 0x0E);
				pos |= ((uint16_t)inb(0x3D5)) << 8;
				return pos;
			}
			static void setCursorPosition(uint16_t pos)
			{
				outb(0x3D4, 0x0F);
				outb(0x3D5, (uint8_t) (pos & 0xFF));
				outb(0x3D4, 0x0E);
				outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
				return;
			}
			static void endl()
			{

			}
			static void advanceCursor(int n)
			{
				setCursorPosition(getCursorPosition() + n);
			}

			static void putc(char c)
			{
				uint16_t* buffer = (uint16_t*)0xB8000;
				buffer[getCursorPosition()] =
				// VGA mem entries look like so:
				// 00000000 00000000
				// CCCCCCCC XBBBFFFF
				// F: 	foreground color
				// B: 	background color
				// C:	ascii char
				// X:	either tell vga it is bright color OR enables blinking..

				// '0' is black, '15' is white
				(c | (15 | 0 << 4) << 8);

				advanceCursor(1);
				return;
			}
		public:
			static void print(const char* str)
			{
				//calculate string length
				int len = 0;
				while (str[len])
					len++;

				// put each char from the string into kernel msg buffer
				for(int i = 0; i < len; i++)
				{
					switch(str[i])
					{
						case '\n':
							setCursorPosition((80 * (getCursorPosition() / 80)) + 80);
							break;
						case '\t':
							setCursorPosition(getCursorPosition() + 4);
							break;
						default:
							putc(str[i]);
							break;
					}
				}
			}
		};
}
*/
