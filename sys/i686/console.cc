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

// Basic VGA output
namespace Console
{
    namespace
    {
        // Get the cursor position from vga mem
        void GetPosition()
        {
        	
        	// return cursor position
        }

        // Print char to screen
        void PutChar(char c, size_t position)
        {
        	// write 'c' to vga mem at coordinates from 'position'
        }
    }
    // Functions accessible to kmain

    // Print line of text
    void Console::Println(const char* data)
    {
        /*
    	for(size_t i = 0; i < sizeof(data); i++)			// go through each char and print
   		   PutChar(data[i], GetPosition());
        */
    }

    // Clear the screen
    void Console::Clear()
    {
    	// Clear all fonts from vram and reset cursor
    }
}

namespace Kernel
{
    static class TerminalManager
    {
    public:
        static uint16_t TerminalPosition;

        uint8_t GetTerminalPositionX()
        {
            return (uint8_t)TerminalPosition >> 8;
        }

        uint8_t GetTerminalPositionY()
        {
            return (uint8_t)TerminalPosition << 8;
        }

        void SetTerminalPosition(uint8_t x, uint8_t y)
        {
            uint16_t finalPosition;

            finalPosition = 0 << x << y;
        }
    
    };
}

// namespace Driver {
//     TerminalManager.TerminalPosition
// }