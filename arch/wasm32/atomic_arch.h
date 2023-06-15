#define a_cas a_cas
static inline int a_cas(volatile int *p, int t, int s)
{
    if (*p == t) {
        *p = s;
        return t;
    } else {
        return *p;
    }
}

// #define a_swap a_swap
// static inline int a_swap(volatile int *p, int v)
// {
//     int old = *p;
//     *p = v;
// 	return old;
// }

// #define a_fetch_add a_fetch_add
// static inline int a_fetch_add(volatile int *p, int v)
// {
//     int last = *p;
//     *p += v;
// 	return last;
// }

// #define a_and a_and
// static inline void a_and(volatile int *p, int v)
// {
// 	*p &= v;
// }

// #define a_or a_or
// static inline void a_or(volatile int *p, int v)
// {
//     *p |= v;
// }

// #define a_inc a_inc
// static inline void a_inc(volatile int *p)
// {
//     *p += 1;
// }

// #define a_dec a_dec
// static inline void a_dec(volatile int *p)
// {
//     *p -= 1;
// }

// // #define a_store a_store
// // static inline void a_store(volatile int *p, int x)
// // {

// // 	__asm__ __volatile__(
// // 		"mov %1, %0 ; lock ; orl $0,(%%esp)"
// // 		: "=m"(*p) : "r"(x) : "memory" );
// // }

// #define a_barrier a_barrier
// static inline void a_barrier()
// {
// }

// #define a_spin a_spin
// static inline void a_spin()
// {
// }

// #define a_crash a_crash
// static inline void a_crash()
// {
// }

// // #define a_ctz_64 a_ctz_64
// // static inline int a_ctz_64(uint64_t x)
// // {
// // 	int r;
// // 	__asm__( "bsf %1,%0 ; jnz 1f ; bsf %2,%0 ; add $32,%0\n1:"
// // 		: "=&r"(r) : "r"((unsigned)x), "r"((unsigned)(x>>32)) );
// // 	return r;
// // }

// // #define a_ctz_32 a_ctz_32
// // static inline int a_ctz_32(uint32_t x)
// // {
// // 	int r;
// // 	__asm__( "bsf %1,%0" : "=r"(r) : "r"(x) );
// // 	return r;
// // }

// // #define a_clz_32 a_clz_32
// // static inline int a_clz_32(uint32_t x)
// // {
// // 	__asm__( "bsr %1,%0 ; xor $31,%0" : "=r"(x) : "r"(x) );
// // 	return x;
// // }
