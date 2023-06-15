// __asm__(
// ".text\n"
// ".weak _DYNAMIC \n"
// ".hidden _DYNAMIC \n"
// ".global " START "\n"
// START ":\n"
// "	xor %ebp,%ebp \n"
// "	mov %esp,%eax \n"
// "	and $-16,%esp \n"
// "	push %eax \n"
// "	push %eax \n"
// "	call 1f \n"
// "1:	addl $_DYNAMIC-1b,(%esp) \n"
// "	push %eax \n"
// "	call " START "_c \n"
// );

#ifdef SHARED

#else
void _start_c(long* p);

weak void _init();
weak void _fini();

weak int __main_argc_argv(int argc, char* argv[]);
weak int __main_void();
weak int main(int argc, char* argv[]) __asm__("main");

static int main_trampoline(int argc, char* argv[], char* envp[]) {
    int possible_entries = 0;

    if (__main_argc_argv) {
        possible_entries += 1;
    }

    if (__main_void) {
        possible_entries += 1;
    }

    if (main) {
        possible_entries += 1;
    }

    if (possible_entries != 1) {
        // if no or more than one entry is available, we abort
        __asm__ ("unreachable");
    }

    if (__main_argc_argv) {
        return __main_argc_argv(argc, argv);
    } else if (__main_void) {
        return __main_void();
    } else {
        return main(argc, argv);
    }
}

int __libc_start_main(int (*)(), int, char **,
	void (*)(), void(*)(), void(*)());

void _start(int argc, char* argv[]) {
    __libc_start_main(main_trampoline, argc, argv, _init, _fini, 0);
}
#endif
