
// If debugging is enabled, we create the LOG function. If not, we create empty macros so the code compiles but no code is actually built into the kernel
#ifdef __DEBUG

#include <kernel.h>
#include <iobus.h>
#include <debug.h>

using kstd::inb;
using kstd::outb;

const int PORT = 0x3F8;		// COM1

void INIT_SERIAL()
{
	outb(PORT + 1, 0x00);
	outb(PORT + 3, 0x80);
	outb(PORT + 0, 0x03);
	outb(PORT + 1, 0x00);
	outb(PORT + 3, 0X03);
	outb(PORT + 2, 0xC7);
	outb(PORT + 4, 0x0B);
	outb(PORT + 4, 0x1E);
	outb(PORT + 0, 0xAE);
						
	if(inb(PORT + 0) != 0xAE)
		return; // we should find an alternate way to let us know that the serial com is faulty.
	outb(PORT + 4, 0x0F);
}

void SERIAL_OUT(char c)
{
			while((inb(PORT + 5) & 0x20) == 0);
			outb(PORT, c);
}

void LOG(const char *message)
{
	//calculate string length
	int len = 0;
	while (message[len])
		len++;

	// put each char from the string into kernel msg buffer
	for(int i = 0; i < len; i++)
		SERIAL_OUT(message[i]);
}

#endif // __DEBUG