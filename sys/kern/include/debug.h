#ifndef __DEBUG_H__
#define __DEBUG_H__

// If debugging is enabled, we create the LOG function. If not, we create empty macros so the code compiles but no code is actually built into the kernel
#ifdef __DEBUG
namespace kernel {
	void INIT_SERIAL();
	void SERIAL_OUT(char c);
	extern "C" void LOG(const char *message);
}
#else

// Dummy macros so the calls to LOG don't throw errors
#define INIT_SERIAL()
#define LOG(a)

#endif // __DEBUG

#endif // __DEBUG_H__