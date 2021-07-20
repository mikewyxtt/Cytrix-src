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

namespace cytrix
{
    namespace kernel
    {
        // called after all arch specific initialization is done
        void main() 
        {

            Console::log("Entered main().\n");
            while(1)
            {
                //Main kernel loop to go here.
                int i = 0;
                i++;
            }
        }
    }
}