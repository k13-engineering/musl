#include <setjmp.h>

_Noreturn void longjmp (jmp_buf buf, int ret) {
    __asm__ ("unreachable");
}
