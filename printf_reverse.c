#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/**
 * print_reverse - Prints a string in reverse.
 * @str: The string to be printed in reverse.
 */
void print_reverse(const char *str) {
    int len = strlen(str);

    /* Use a loop variable declared before the loop in C90 style */
    int i;
    for (i = len - 1; i >= 0; i--) {
        putchar(str[i]);
    }
}

/**
 * custom_printf - Custom printf-like function with additional specifier.
 * @format: Format string specifying the output format.
 * @...: Variable arguments based on the format.
 *
 * Description: This function simulates the behavior of printf with an additional %r specifier
 * that prints a string in reverse.
 */
void custom_printf(const char *format, ...) {
    va_list args;

    /* Declare variables at the beginning of the block in C90 style */
    const char *str;

    va_start(args, format);

    while (*format) {
        if (*format != '%') {
            putchar(*format);
        } else {
            format++;
            if (*format == 'r') {
                /* Handle %r specifier */
                str = va_arg(args, const char *);
                print_reverse(str);
            } else {
                /* Handle other specifiers if needed
                   For simplicity, we just print the specifier as is */
                putchar('%');
                putchar(*format);
            }
        }
        format++;
    }

    va_end(args);
}
