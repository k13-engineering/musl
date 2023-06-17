#include <setjmp.h>
#include <unistd.h>

int setjmp (jmp_buf buf) {
    const char* error_msg = "error: setjmp not implemented\n";
	write(2, error_msg, sizeof(error_msg) - 1);

    __asm__ ("unreachable");
}
