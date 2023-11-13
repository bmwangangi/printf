#include "main.h"

/**
 * _printf - Custom printf-like function with variable arguments.
 * @format: Format string specifying the output format.
 *
 * Description: This function simulates the behavior of printf.
 *
 * Return: The number of characters printed or -1 if an error occurs.
 */
int _printf(const char *format, ...)
{
    int outputCount = 0;
    va_list args;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (*format)
    {
        if (*format != '%')
        {
            putchar(*format);
            outputCount++;
        }
        else
        {
            format++;
            if (*format == '\0')
                break;

            if (*format == '%')
            {
                putchar(*format);
            }
            else if (*format == 'c')
            {
                char c = va_arg(args, int);
                putchar(c);
                outputCount++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                int strLen = 0;
		int a;

                while (str[strLen] != '\0')
                    strLen++;

                putchar(*str);
                outputCount++;

                for (a = 1; a < strLen; a++)
                {
                    putchar(*(str + a));
                    outputCount++;
                }
            }
        }
        format++;
    }

    va_end(args);
    return (outputCount);
}

