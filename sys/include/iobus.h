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

#ifndef __IOBUS_H__
#define __IOBUS_H__

namespace cytrix
{
    namespace kernel
    {
        class IOBus
        {
        	/*
                "inline" functions that are to be called in other files/functions
                must be declared in the header. if they are not, the linker will
                return an "undefined reference" error
             */
        public:
            static inline __attribute__((always_inline)) unsigned char Input(uint32_t Port)
            {
                unsigned char ret;

                #if TARGET_ARCH == i386
                __asm__ volatile ("inb %%dx,%%al":"=a" (ret):"d" (Port));
                #endif

                return ret;
            }

            static inline __attribute__((always_inline)) void Output(uint32_t Port, unsigned char Value)
            {
            	#if TARGET_ARCH == i386
                __asm__ volatile ("outb %%al,%%dx": :"d" (Port), "a" (Value));
                #endif
                return;
            }
        };
    }
}
#endif
