
#include <stdint.h>
#include "kstdio.h"
#include <iobus.h>

using namespace kernel::iobus;

namespace kstd {

	// temporary implementation for the log func until we have a working framebuffer
	namespace
	{
		class VGA
		{
		private:
			static uint16_t getCursorPosition()
			{
				uint16_t pos = 0;
				outb(0x3D4, 0x0F);
				pos |= inb(0x3D5);
				outb(0x3D4, 0x0E);
				pos |= ((uint16_t)inb(0x3D5)) << 8;
				return pos;
			}
			static void setCursorPosition(uint16_t pos)
			{
				outb(0x3D4, 0x0F);
				outb(0x3D5, (uint8_t) (pos & 0xFF));
				outb(0x3D4, 0x0E);
				outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
				return;
			}
			static void endl()
			{

			}
			static void advanceCursor(int n)
			{
				setCursorPosition(getCursorPosition() + n);
			}

			static void putc(char c)
			{
				uint16_t* buffer = (uint16_t*)0xB8000;
				buffer[getCursorPosition()] =
				// VGA mem entries look like so:
				// 00000000 00000000
				// CCCCCCCC XBBBFFFF
				// F: 	foreground color
				// B: 	background color
				// C:	ascii char
				// X:	either tell vga it is bright color OR enables blinking..

				// '0' is black, '15' is white
				(c | (15 | 0 << 4) << 8);

				advanceCursor(1);
				return;
			}
		public:
			static void print(const char* str)
			{
				//calculate string length
				int len = 0;
				while (str[len])
					len++;

				// put each char from the string into kernel msg buffer
				for(int i = 0; i < len; i++)
				{
					switch(str[i])
					{
						case '\n':
							setCursorPosition((80 * (getCursorPosition() / 80)) + 80);
							break;
						case '\t':
							setCursorPosition(getCursorPosition() + 4);
							break;
						default:
							putc(str[i]);
							break;
					}
				}
			}
		};

	}
	void log(const char* msg)
	{
		VGA::print(msg);
		// TODO:
		// record msg to /var/logs/<DMESG_FILE?>
		// print msg to active framebuffer
		return;
	}
} // end namespace kstd
