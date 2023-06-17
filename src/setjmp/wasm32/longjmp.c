#include <setjmp.h>

_Noreturn void longjmp (jmp_buf buf, int ret) {
    const char* error_msg = "error: longjmp not implemented\n";
	write(2, error_msg, sizeof(error_msg) - 1);

    __asm__ ("unreachable");
}
