#pragma once

#define va_list __buildin_va_list
#define va_start __buildin_va_start
#define va_end __buildin_va_end
#define va_arg __buildin_va_arg

void printf(const char *fmt, ...);
