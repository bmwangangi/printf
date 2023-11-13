#include "main.h"

/**
 * print_integer - Used to print integers
 * @argument: argument to check
 *
 * Return: number of characters printed
 */
int print_integer(va_list argument)
{
	int v = va_arg(argument, int);
	int num, last = v % 10, digit, exp = 1;
	int a = 1;

	v = v / 10;
	num = v;

	if (last < 0)
	{
		putchar('_');
		num = -num;
		v = -v;
		last = -last;
		a++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = v;
		while (exp > 0)
		{
			digit = num / exp;
			putchar(digit + '0');
			num = num - (digit * exp);
			exp = exp / 10;
			a++;
		}
	}
	putchar(last + '0');

	return (a);
}

#include "main.h"

/**
 * print_decimal - print integers
 * @argument: the argument to print
 *
 * Return: number of characters printed
 */
int print_decimal(va_list argument)
{
	int b = va_arg(argument, int);
	int num, last = b % 10, digit, exp = 1;
	int d = 1;

	b = b / 10;
	num = b;

	if (last < 0)
	{
		putchar('_');
		num = -num;
		b = -b;
		last = -last;
		d++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = b;
		while (exp > 0)
		{
			digit = num / exp;
			putchar(digit + '0');
			num = num - (digit * exp);
			exp = exp / 10;
			d++;
		}
	}
	putchar(last + '0');

	return (d);
} 
