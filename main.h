#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int _printf(const char *format, ...);
int custom_printf(const char *style, ...);
int print_integer(int p);

#endif
