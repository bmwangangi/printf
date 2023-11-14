#include "main.h"

/**
 * _putchar - to write character x to std output
 * @x: the character to print
 *
 * Return: success or -1 for error
 */
int _putchar(char x)
{
	return(write(1, &x, 1));
}
