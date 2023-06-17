
struct user_desc {
	unsigned int  entry_number;
	unsigned int  base_addr;
	unsigned int  limit;
	unsigned int  seg_32bit:1;
	unsigned int  contents:2;
	unsigned int  read_exec_only:1;
	unsigned int  limit_in_pages:1;
	unsigned int  seg_not_present:1;
	unsigned int  useable:1;
};

static inline uintptr_t __get_tp()
{
	// uintptr_t tp;
	// __asm__ ("movl %%gs:0,%0" : "=r" (tp) );
	// return tp;

	// __asm__("unreachable");
	// return 0;

	struct user_desc desc;

	int ret = __syscall(SYS_get_thread_area, &desc);
	if (ret != 0) {
		__asm__("unreachable");
	}

	return desc.base_addr;
}

#define MC_PC gregs[REG_EIP]
