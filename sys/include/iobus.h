#ifndef __IOBUS_H__
#define __IOBUS_H__
/*
	TODO:
	Create if statements for each arch and include the appropriate iobus header for the
	target architecture. e.g.
	#ifdef i386
	#include <arch/i386/iobus/iobus.h
	#elseif arm
	#include <arch/arm/iobus/iobus.h>
	#endif
*/

namespace Kernel
{
    struct IOBus
    {
    //public:
    	/*
        "inline" functions that are to be used in other files/functions
        must be declared in the header. if they are not, the linker will
        return an "undefined reference" error
         */
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
        	#if TARGET_ARCH==i386
            __asm__ volatile ("outb %%al,%%dx": :"d" (Port), "a" (Value));
            #endif
            return;
        }
    };
}
#endif
