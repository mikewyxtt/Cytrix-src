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

#include <kernel.h>
#include <console.h>

using namespace Kernel;

namespace Kernel
{
    void Console::Initialize()
    {
        VGA::Cursor::SetPosition(0,0);
        // TODO: Clear screen.
        return;
    }
    size_t Console::Cursor::GetPosition()
    {
        return VGA::Cursor::GetPosition();
    }

    void Console::Cursor::SetPosition(uint8_t X, uint8_t Y)
    {
        return VGA::Cursor::SetPosition(X,Y);
    }

    void Console::Cursor::Disable()
    {
        VGA::Cursor::Disable();
    }

    void Console::Cursor::Enable()
    {
        VGA::Cursor::Enable();
    }

    // Print char to screen
    void Console::PutChar(char Char)
    {
        Console::Cursor cursor;
    	VGA::PutChar(Char, cursor.GetPosition(), VGA::Color::Black, VGA::Color::White);
        return;
    }

    void Console::Println(const char* String)
    {
        for(int i = 0; i < String[i]; i++)
        {
            switch(String[i])
            {
                case '\n':
                    // call putc
                    break;
                default:
                    // call putc
                    break;
            }
        }
        return;
    }

    // Clear the screen
    void Console::Clear()
    {
    	// Clear all fonts from vram and reset cursor
        return;
    }
}
