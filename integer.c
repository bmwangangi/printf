#include "main.h"

/**
 * print_int - Prints an integer
 * @args: the list of arguments
 * Return: the amount of character
 */

int print_int(va_list args)
{
	int number_length;

	number_length = print_num(args);
	return (number_length);
}


/**
 * print_num - used to  print a num
 * @args: List of arguments
 * Return: The number of arguments printed
 */

int print_num(va_list args)
{
	int a;
	int division;
	int length;
	unsigned int number;

	a  = va_arg(args, int);
	division = 1;
	length = 0;

	if (a < 0)
	{
		length += putchar('-');
		number = a * -1;
	}
	else
		number  = a;

	for (; number / division > 9; )
		division *= 10;

	for (; division != 0; )
	{
		length += putchar('0' + number / division);
		number  %= division;
		division /= 10;
	}
	return (length);
}


