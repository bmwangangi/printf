#include "main.h"

/**
 * custom_printf - Custom printf function with limited functionality
 * @style: Format string containing conversion specifiers
 *
 * Return: Number of characters printed
 */

int custom_printf(const char *style, ...)
{
	va_list arguments;
	int count = 0;
	const char *str = style;

	va_start(arguments, style);

	while (str && *str)
	{
		if (*str == '%' && (*(str + 1) == 'd' || *(str + 1) == 'i'))
		{
			count += print_integer(va_arg(arguments, int));
			str += 2;
		}
		else
		{
			putchar(*str);
			count++;
			str++;
		}
	}

	va_end(arguments);
	return (count);
}

/**
 * print_integer - Print the integers
 * @p: Integer to be printed
 *
 * Return: Number of characters printed
 */

int print_integer(int p)
{
	int num, last = p % 10, digit, exp = 1;
	int count = 1;

	p = p / 10;
	num = p;

	if (last < 0)
	{
		putchar('_');
		num = -num;
		p = -p;
		last = -last;
		count++;
	}

	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp *= 10;
			num /= 10;
		}
		num = p;
		while (exp > 0)
		{
			digit = num / exp;
			putchar(digit + '0');
			num -= digit * exp;
			exp /= 10;
			count++;
		}
	}
	putchar(last + '0');
	return (count);
}
