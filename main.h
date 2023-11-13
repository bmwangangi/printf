#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

void print_reverse(const char *str);
void custom_printf(const char *format, ...);
int _printf(const char *format, ...);
int print_integer(va_list argument);
int print_decimal(va_list argument);

#endif
