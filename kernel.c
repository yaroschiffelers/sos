#include "kernel.h"

typedef unsigned char uint8_t;
typedef unsigned char uint32_t;
typedef uint32_t size_t;

// Linker script defined symbols, we're only interested in the addresses
extern char __bss[], __bss_end[], __stack_top[];

struct sbiret sbi_call(long arg0, long arg1, long arg2, long arg3, long arg4, long arg5, long fid, long eid)
{
    register long a0 __asm__("a0") = arg0;
    register long a1 __asm__("a1") = arg1;
    register long a2 __asm__("a2") = arg2;
    register long a3 __asm__("a3") = arg3;
    register long a4 __asm__("a4") = arg4;
    register long a5 __asm__("a5") = arg5;
    register long a6 __asm__("a6") = fid;
    register long a7 __asm__("a7") = eid;

    // Switches to (OpenSBI) M-Mode (from S/Kernel), executes instructions and switches back.
    // Can also be used like a func call to a more privileged CPU mode (sys call)
    __asm__ __volatile__("ecall"
                         : "=r"(a0), "=r"(a1)
                         : "r"(a0), "r"(a1), "r"(a2), "r"(a3), "r"(a4), "r"(a5), "r"(a6), "r"(a7)
                         : "memory");

    return (struct sbiret){.error = a0, .value = a1};
}

void putchar(char ch)
{
    sbi_call(ch, 0, 0, 0, 0, 0, 0, 1 /* Console Putchar */);
}

void *memset(void *buf, char c, size_t n)
{
    uint8_t *p = (uint8_t *)buf;

    while (n--)
    {
        *p++ = c;
    }

    return buf;
}

void kernel_main(void)
{
    // // Set bss to 0, since not all bootloaders recognize and zero-clear the bss section
    // memset(__bss, 0, (size_t)__bss_end - (size_t)__bss);

    // // Inf loop and kernel exit
    // for (;;)
    //     ;

    // Test
    const char *s = "\n\nwomp womp!\n";
    for (int i = 0; s[i] != '\0'; i++)
    {
        putchar(s[i]);
    }

    for (;;)
    {
        __asm__ __volatile__("wfi");
    }
}

__attribute__((section(".text.boot")))
__attribute__((naked)) // Ensures that the inline assembly code is the exact function body
void
boot(void)
{
    __asm__ __volatile__(
        "mv sp, %[stack_top]\n" // Set the stack pointer
        "j kernel_main\n"       // Jump to the kernel main function
        :
        : [stack_top] "r"(__stack_top) // Pass the stack top address as %[stack_top]
    );
}
