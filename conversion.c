#include "main.h"

/**
 * write - placeholder function for demonstration purposes
 * @format: format specifier
 * @args: variable arguments list
 * @printed: current count of printed characters
 * Return: updated count of printed characters
 */
int write(const char *format, va_list args, int printed);

/**
 * _printf - implementation of the inbuilt printf
 * @format: the format specifier
 * Return: the formatted string
 */
int _printf(const char *format, ...)
{
    int printed = 0;

    va_list args;
    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            printed = write(format, args, printed);
            format++;
        }
        else
        {
            putchar(*format);
            printed++;
            format++;
        }
    }

    va_end(args);
    return printed;
}
