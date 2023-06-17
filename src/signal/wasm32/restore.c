#include <unistd.h>


void __restore() {
	const char* error_msg = "error: __restore not implemented\n";
	write(2, error_msg, sizeof(error_msg) - 1);

	__asm__("unreachable");
}

void __restore_rt() {
	const char* error_msg = "error: __restore_rt not implemented\n";
	write(2, error_msg, sizeof(error_msg) - 1);

	__asm__("unreachable");
}