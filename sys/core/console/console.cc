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
#include <console.h>

using namespace Kernel;

namespace Kernel
{
    // void Console::Initialize()
    // {
    //     VGA::Cursor::SetPosition(0,0);
    //     // TODO: Clear screen.
    //     return;
    // }
    // size_t Console::Cursor::GetPosition()
    // {
    //     return VGA::Cursor::GetPosition();
    // }

    // void Console::Cursor::SetPosition(uint8_t X, uint8_t Y)
    // {
    //     return VGA::Cursor::SetPosition(X,Y);
    // }

    // void Console::Cursor::Disable()
    // {
    //     VGA::Cursor::Disable();
    // }

    // void Console::Cursor::Enable()
    // {
    //     VGA::Cursor::Enable();
    // }

    // Print char to screen
    void Console::PutChar(char c)
    {
        // Console::Cursor cursor;
    	// VGA::PutChar(Char, cursor.GetPosition(), VGA::Color::Black, VGA::Color::White);
        return;
    }

    void Console::Println(const char* string)
    {
        // for(int i = 0; i < String[i]; i++)
        // {
        //     Console::Cursor cursor;
        //     cursor.Position = cursor.GetPosition();
        //     switch(string[i])
        //     {
        //         case '\n':
        //             // call putc
        //             break;
        //         default:
        //             VGA::PutChar(String[i],cursor.Position, VGA::Color::White, VGA::Color::Black);
        //             cursor.Position++;
        //             cursor.SetPosition(cursor.Position,0);
        //             break;
        //     }
        // }
        return;
    }

    // // Clear the screen
    // void Console::Clear()
    // {
    // 	// Clear all fonts from vram and reset cursor
    //     return;
    // }
}
