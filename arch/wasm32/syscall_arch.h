#define __SYSCALL_LL_E(x) \
((union { long long ll; long l[2]; }){ .ll = x }).l[0], \
((union { long long ll; long l[2]; }){ .ll = x }).l[1]
#define __SYSCALL_LL_O(x) __SYSCALL_LL_E((x))

__attribute__((import_module("env"), import_name("__syscall0"))) long __syscall0(long n);
__attribute__((import_module("env"), import_name("__syscall1"))) long __syscall1(long n, long a1);
__attribute__((import_module("env"), import_name("__syscall2"))) long __syscall2(long n, long a1, long a2);
__attribute__((import_module("env"), import_name("__syscall3"))) long __syscall3(long n, long a1, long a2, long a3);
__attribute__((import_module("env"), import_name("__syscall4"))) long __syscall4(long n, long a1, long a2, long a3, long a4);
__attribute__((import_module("env"), import_name("__syscall5"))) long __syscall5(long n, long a1, long a2, long a3, long a4, long a5);
__attribute__((import_module("env"), import_name("__syscall6"))) long __syscall6(long n, long a1, long a2, long a3, long a4, long a5, long a6);
