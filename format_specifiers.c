#include "main.h"

/**
 * print_integer - Used to print integers
 * @argument: argument to check
 *
 * Return: number of printed characters
 */

int print_integer(va_list argument)
{
	int v = va_arg(argument, int);
	int number, last = v % 10, digit, expo = 1;
	int a = 1;

	v = v / 10;
	number = v;

	if (last < 0)
	{
		putchar ('_');
		number = -number;
		v = -v;
		last = -last;
		a++;
	}
	if (number > 0)
	{
		while (number / 10 != 0)
		{
			expo = expo * 10;
			number = number / 10;
		}
		number = v;
		while (expo > 0)
		{
			digit = number / expo;
			putchar(digit + '0');
			number = number - (digit * expo);
			expo = expo / 10;
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
 * Return: number of printed characters
 */

int print_decimal(va_list argument)
{
	int b = va_arg(argument, int);
	int number, last = b % 10, digit, expo = 1;
	int d = 1;

	b = b / 10;
	number = b;

	if (last < 0)
	{
		putchar ('_');
		number = -number;
		b = -b;
		last = -last;
		d++;
	}
	if (number > 0)
	{
		while (number / 10 != 0)
		{
			expo = expo * 10;
			number = number / 10;
		}
		number = b;
		while (expo > 0)
		{
			digit = number / expo;
			putchar(digit + '0');
			number = number - (digit * expo);
			expo = expo / 10;
			d++;
		}
	}
	putchar(last + '0');

	return (d);
}

#include "main.h"

/**
 * main - Entry point of program
 *
 * Return: 0
 */

int main(void)
{
	int num1 = 132;
	int num2 = -421;

	printf("Integer: %i\n", num1);
	printf("Decimal: %d\n", num2);

	return (0);
}
