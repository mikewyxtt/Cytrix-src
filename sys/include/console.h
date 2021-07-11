/*
 * console.h
 *
 * VGA console declaration
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

#include <kernel.h>

namespace Kernel
{
    class Console
    {
    public:
        static void GetPosition();
        static void SetPosition();
        static void PutChar(char c, size_t position);      // Print char to screen
    	static void Println(const char* data);		// Classic print function
    	static void Clear();          				// Clear screen

        // enum Color
    };
}

#endif