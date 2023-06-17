#include <unistd.h>

void sigsetjmp() {
	const char* error_msg = "error: sigsetjmp not implemented\n";
	write(2, error_msg, sizeof(error_msg) - 1);
	__asm__("unreachable");
}
