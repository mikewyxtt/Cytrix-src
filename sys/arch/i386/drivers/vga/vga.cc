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

#include <kernel.h>
#include "vga.h"
using namespace Kernel;

namespace Kernel
{

	/*inline*/ void VGA::PutChar(char Char,size_t Position, Color Foreground, Color Background)
	{
		/*
        The VGA buffer begins at address 0xB8000

        Entries are made at even intervals, e.g. to print 'Hi' at the top of the screen
        you would put 'H' at 0xB8000 and 'i' at 0xB8001.

        Each entry requires 2 bytes of information. The first byte contains attributes and
        the second contains the char itself.

        The attribute byte is broken up into three different attributes. The first
        4 bits are the background color, the following bit is a setting?, and the
        last 3 bits are the foreground color.

        In this function we take the arguments that the calling function passed in
        and write them to the video memory using this format.

        The forums are saying this is backwards and that the char comes after the attribute?
        */
        uint16_t* Buffer = (uint16_t*)0xB8000;
        Buffer[Position] = (Char | (Foreground | Background << 4) << 8);
	}

	void VGA::Cursor::Enable()
	{
		/*
			Not yet implemented. must work with scan lines and i am
			unfamiliar.
		*/
		return;
	}

	void VGA::Cursor::Disable()
	{
		/*
			Disable the cursor by sending the cursor disable signal??
		 */
		IOBus::Output(0x3D4, 0x0A);
		IOBus::Output(0x3D5, 0x20);
		return;
	}

	size_t VGA::Cursor::GetPosition()
	{
		/*
			Get the cursor position by..??
		 */
		uint16_t pos =0;
		IOBus::Output(0x3D4, 0x0F);
		pos |= IOBus::Input(0x3D5);
		IOBus::Output(0x3D4, 0x0E);
		pos |= ((uint16_t)IOBus::Input(0x3D5)) << 8;
		return pos;
	}

	void VGA::Cursor::SetPosition(uint8_t X, uint8_t Y)
	{
		/*
			Set the cursor position by..??
		 */
		uint16_t pos = Y * 80 + X;
		IOBus::Output(0x3D4, 0x0F);
		IOBus::Output(0x3D5, (uint8_t)(pos & 0xFF));
		IOBus::Output(0x3D4, 0x0E);
		IOBus::Output(0x3D5, (uint8_t)((pos >> 8) & 0xFF));
		return;
	}
}