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

// If debugging is enabled, we create the LOG function. If not, we create empty macros so the code compiles but no code is actually built into the kernel
#ifdef __DEBUG

#include <kernel.h>
#include <io.h>
#include <debug.h>

using kstd::inb;
using kstd::outb;

const int PORT = 0x3F8;		// COM1

// Initializes the serial interface
void INIT_SERIAL()
{
	outb(PORT + 1, 0x00);	// disable interrupts
	outb(PORT + 3, 0x80);	// enable DLAB (set baud rate divisor)
	outb(PORT + 0, 0x03);	// Set divisor to 3 (low byte) 38400 baud
	outb(PORT + 1, 0x00);	//					(high byte)
	outb(PORT + 3, 0X03);	// 8 bits, no parity, one stop bit
	outb(PORT + 2, 0xC7);	// Enable FIFO, clear them, with 14-byte threshold
	outb(PORT + 4, 0x0B);	// IRQs enabled, RTS/DSR
	outb(PORT + 4, 0x1E);	// Set in loopback mode, test the serial chip
	outb(PORT + 0, 0xAE);	// Test serial chip (send byte 0xAE)

	// Check if serial byte is faulty (if it doesn't read 0xAE back from previous outb)					
	if(inb(PORT + 0) != 0xAE)
		return; // we should find an alternate way to let us know that the serial com is faulty.
	outb(PORT + 4, 0x0F);
}

// Sends one 'char' through the serial port
void SERIAL_OUT(char c)
{
			while((inb(PORT + 5) & 0x20) == 0);		// ensure data transit is empty
			outb(PORT, c);
}

// Sends a string through the serial port
void LOG(const char *message)
{
	// Calculate string length
	int len = 0;
	while (message[len])
		len++;

	// go through each 'char' in the string and send it through the serial port
	for(int i = 0; i < len; i++)
		SERIAL_OUT(message[i]);
}

#endif // __DEBUG