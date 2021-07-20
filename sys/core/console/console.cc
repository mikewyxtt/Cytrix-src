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
#include "console.h"

namespace cytrix
{
    namespace kernel
    {
        // Print 'c' to kernel message buffer
        void Console::putChar(char c)
        {
            uint16_t* dmesg = (uint16_t*)0x8000;
            
            // find the next available space in the buffer
            int counter = 0;
            while(dmesg[counter] != 0)
                counter++;
            dmesg[counter] = c;
            return;
        }

        // Print 'string' to kernel message buffer
        void Console::log(const char* msg)
        {
            //calculate string length
            int len = 0;
            while (msg[len])
                len++;
            // put each char from the string into kernel msg buffer
            for(int i = 0; i < len; i++)
            {
                putChar(msg[i]);
            }

            // call our placeholder func to show the msg buffer on display
            show_log();
            return;
        }

        /* quick and dirty function to display the message log. We will delete
            this function once the kernel is able to load the init process
            and load a graphics driver that can display our message log in a 
            way that aligns better with the microkernel ideology
         */
        void Console::show_log()
        {
            const int SCREEN_WIDTH = 80;
            const int SCREEN_HEIGHT = 25;
            uint16_t* dmesg = (uint16_t*)0x8000;
            uint16_t* vid_buffer = (uint16_t*)0xB8000;

            // Disable the cursor
            IOBus::output(0x3D4, 0x0A);
            IOBus::output(0x3D5, 0x20);

            // clear the screen
            for(int i=0; i<(SCREEN_WIDTH * SCREEN_HEIGHT); i++)
                vid_buffer[i] = ' ';

            /* next we go through the *entire* kernel msg buffer
                char by char and display it to the screen. it clears the 
                screen everytime its called and is obviously a horrible way
                to implement a console. it is only used as a placeholder until
                we can route our stdio properly later down the line. this will
                allow us to have a standard function for message printing from
                inside the kernel.
             */
            int cursor_pos = 0;
            int line_number = 1;
            for(int i=0; i<(SCREEN_WIDTH * SCREEN_HEIGHT); i++)
            {
                switch(dmesg[i])
                {
                    case '\n':
                        cursor_pos = (SCREEN_WIDTH * line_number);
                        line_number++;
                        break;
                    case '\t':
                        cursor_pos += 4;
                        break;
                    default:
                        vid_buffer[cursor_pos] = (dmesg[i] | (15 | 0 << 4) << 8);
                        cursor_pos++;
                        break;
                }
            }
            return;
        }
    }
}
