#pragma once

typedef int bool;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef uint32_t size_t;
typedef uint32_t paddr_t; // physical memory address
typedef uint32_t vaddr_t; // virtual memory address (equivalent to uintptr_t)

#define true 1
#define false 0
#define NULL ((void *)0)
#define va_list __buildin_va_list
#define va_start __buildin_va_start
#define va_end __buildin_va_end
#define va_arg __buildin_va_arg

// rounds value to nearest multiple of align. Align must be a power of 2
#define align_up(value, align) __buildin_align_up(value, align) 

// checks if value is a multiple of align. Align must be a power of 2
#define is_aligned(value, align) __buildin_is_aligned(value, align)

// returns the offset of a member within a structure (x amount of bytes from start)
#define offsetof(type, member) __buildin_offsetof(type, member)

void *memset(void *buf, char c, size_t n);
void *memcpy(void *dst, const void *src, size_t n);
void *strcpy(char *dst, const char *src);
int strcmp(const char *s1, const char *s2);
void printf(const char *fmt, ...);
