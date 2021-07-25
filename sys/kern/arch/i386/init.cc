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
#include <debug.h>

namespace kernel {
    extern void main();

    // Jump in from entry.s
    extern "C" void _init()
    {
        // Initialize the serial console if we debugging is enabled
        #ifdef __DEBUG
        INIT_SERIAL();
        #endif
        LOG("Entered _init\n");

        // Begin main kernel loop
        LOG("Leaving _init\n");
        main();
    }
}
