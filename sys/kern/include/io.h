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

#ifndef __IO_H__
#define __IO_H__

#include <kernel.h>

namespace kernel {

    // "inline" functions that are to be called in other files/functions
    //  must be declared in the header. if they are not, the linker will
    //  return an "undefined reference" error
    static inline __attribute__((always_inline)) unsigned char inb(uint32_t Port)
    {
        unsigned char ret;

        #if TARGET_ARCH == i386
        __asm__ volatile ("inb %%dx,%%al":"=a" (ret):"d" (Port));
        #endif

        return ret;
    }

    static inline __attribute__((always_inline)) void outb(uint32_t Port, unsigned char Value)
    {
        #if TARGET_ARCH == i386
        __asm__ volatile ("outb %%al,%%dx": :"d" (Port), "a" (Value));
        #endif
        return;
    }
}
#endif // end __IO_H__
