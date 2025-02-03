#pragma once

typedef int bool;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef uint32_t size_t;
typedef uint32_t paddr_t;
typedef uint32_t vaddr_t;

#define true 1
#define false 0
#define NULL ((void *)0)
#define align_up(value, align) __buildin_align_up(value, align)
#define is_aligned(value, align) __buildin_is_aligned(value, align)
#define offsetof(type, member) __buildin_offsetof(type, member)
#define va_list __buildin_va_list
#define va_start __buildin_va_start
#define va_end __buildin_va_end
#define va_arg __buildin_va_arg

void *memset(void *buf, char c, size_t n);
void *memcpy(void *dst, const void *src, size_t n);
void *strcpy(char *dst, const char *src);
int strcmp(const char *s1, const char *s2);
void printf(const char *fmt, ...);
