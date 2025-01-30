typedef unsigned char uint8_t;
typedef unsigned char uint32_t;
typedef uint32_t size_t;

#include "kernel.h"

// Linker script defined symbols, we're only interested in the addresses
extern char __bss[], __bss_end[], __stack_top[];

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
    // Set bss to 0, since not all bootloaders recognize and zero-clear the bss section
    memset(__bss, 0, (size_t)__bss_end - (size_t)__bss);

    // Inf loop and kernel exit
    for (;;)
        ;
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
