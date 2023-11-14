#include "main.h"

/**
 *  * print_str - Prints a string
 *   * @args: the list of arguments
 *    *
 *     * Return: Number of characters printed.
 *      */
int print_str(va_list args)
{
	    int b;
	        char *string;

		    string = va_arg(args, char *);
		        if (string == NULL)
				        string = "(null)";
			    for (b = 0; string[b] != '\0'; b++)
				            putchar(string[b]);

			        return (b);
}
