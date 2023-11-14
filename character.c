#include "main.h"

/**
 * print_character - used to print a character
 * @args: the arguments
 *
 * Description: prints character
 *
 * Return: 1
 */
int printf_character(va_list args)
{
	char string;

	string = va_arg(args, int);
	_putchar(string);
		return (1);
}
