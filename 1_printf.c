#include "main.h"

/**
 * _printf - custom like printf function.
 * @format: specifying the output format.
 *
 * Description: this function simulates the behaviour of printf.
 *
 * Return: the number of characters printed or -1 if an error occurs.
 */

int _printf(const char *format, ...)
{
	int outputcount = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if(*format == '%')
		{
			putchar(*format);
			outputcount++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
				putchar(*format);
			else if (*format == 'c')
			{
				char c = va_arg(args, int);
				putchar(c);
				outputcount++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);
				int str_len = 0;
				int a;

				while(str[str_len] != '\0')
					str_len++;

				putchar(*str);
				outputcount++;

				for (a = 1; a < str_len; a++)
				{
					putchar(*(str+a));
					outputcount++;
				}
			}
			format++;
		}
	}
	va_end(args);
	return (outputcount);
}


