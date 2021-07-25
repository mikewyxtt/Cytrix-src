/*
 * This file is a part of Chimera
 * 
 * Copyright (c) 2021
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

#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include <kernel.h>

namespace chimera
{
    namespace kernel
    {
    	class Console
    	{
    	public:
    		static void log(const char* msg); // Print message to kernel msg buffer
    	private:
    		static void putChar(char c);	// Print char to kernel msg buffer
    		static void show_log();
    	};
    }
}
#endif