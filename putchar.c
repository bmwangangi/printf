#include "main.h"

/**
 * betty_putchar - Writes a character to standard output.
 * @x: The character to print.
 *
 * Return: On success, returns 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int betty_putchar(char x)
{
	return (write(1, &x, 1));
}

/**
 * betty_puts - Prints a string to standard output.
 * @string: Pointer to the string to print.
 *
 * Return: Number of characters written (excluding null byte).
 */
int betty_puts(char *string)
{
	register short a;

	for (a = 0; string[a]; a++)
		betty_putchar(string[a]);
	return (a);
}

