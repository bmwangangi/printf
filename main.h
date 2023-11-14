#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int _printf(const char *format, ...);
int print_binary_form(va_list args, char trab[],
        int evans, int diameter, int accurate, int measurement);
int print_integer(va_list args, char trab[],
        int evans, int diameter, int accurate, int measurement);
int print_the_percent(va_list args, char trab[],
        int evans, int diameter, int accurate, int measurement);
int print_string(va_list args, char trab[],
        int evans, int diameter, int accurate, int measurement);
int print_chararacter(va_list args, char trab[],
        int evans, int diameter, int accurate, int measument);
int get_flags(const char *format, int *index);
int print_rot13string(va_list args, char trab[], int evans, int diameter, int accurate, int measurement);
int print_non_printable(va_list args, char trab[], int evans, int diameter, int accurate, int measurement);
int print_pointer(va_list args, char trab[], int evans, int diameter, int accurate, int measurement);
int handle_print(const char *format, int *code, va_list listing, char buffer[],
        int flags, int width, int precision, int size);
int determineArgumentSize(const char *formatSpecifier, int *currentIndex);
int calculatePrintWidth(const char *formatSpecifier, int *currentIndex, va_list argumentsList);




#endif
