#include <setjmp.h>

int setjmp (jmp_buf buf) {
    __asm__ ("unreachable");
}
