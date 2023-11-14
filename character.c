#include "main.h"

/**
 * print_character - Prints a character
 * @listing: List of arguments
 * 
 * Return: Number of characters printed.
 */
int print_character(va_list listing)
{
	putchar(va_arg(listing, int));
	return (1);
}

