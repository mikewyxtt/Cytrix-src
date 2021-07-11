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

using namespace Kernel;

void TestFunc();



// Jump in from entry.s
extern "C" void _init() 
{

    //Console::Cursor::Disable();
    // outportb(0x3D4, 0x0A);
    // outportb(0x3D5, 0x20);

    


    // __asm__
    //     (
    //     "pushf\n"
    //     "push %eax\n"
    //     "push %edx\n"

    //     "mov %dx, 0x3D4\n"
    //     "mov %al, 0xA\n"
    //     "outb %%dx, %%al"
    //     );
}



void TestFunc()
{

    /*
    Important notes:
    - video buffer address is 0xB8000
    - the first 8 bits are the attribute data. the lowest 4 bits are the 
        fg color and the highest 3 are the bg color. the 7th bit is the mode?
    - 


    */

    /* 
    use 16 bit variable to hold coordinates and attributes?
    eg
    0000 0000
    XXXX YYYY
    this would work for all screen resolutions.
    1920 1080
    0080 0025
    etc.

    */
    uint16_t* VRAM = (uint16_t*)0xB8000; // map variable VRAM to address in mem
    uint16_t output = (VRAM[0] & ('x' << 8 | ~VRAM[0]));

    VRAM[0] = output;

    unsigned char c = 'a';
    output = c;
    //real_buffer[position[0]] = 'a' | 0x1F << 8;
    return;
}