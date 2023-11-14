#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

#define NULL_STRING "(null)"
#define NUL '\0'

int print_int(va_list args);
int print_num(va_list args);
int print_str(va_list args);
int print_character(va_list listing);
int print_percentage(__attribute__((unused)) va_list args);

#endif
