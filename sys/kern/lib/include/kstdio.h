#ifndef __KSTDIO_H__
#define __KSTDIO_H__

namespace kstd {
	void log(const char* message);	// Output msg to /var/logs/<DMESG?> and/or active framebuffer
}
#endif // __KSTDO_H__