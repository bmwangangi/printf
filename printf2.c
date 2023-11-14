#include "main.h"

/**
 * _printf - uses the main string to print formatted output
 * @format: a string
 * Return: characters printed
 */

int _printf(const char *format, ...)
{
	int chars;
	conver_t f_forms[] = {
		{"d", print_integer},
		{"%", print_percentage},
		{"i", print_integer},
		{"c", print_character},
		{"s", print_string},
		{"b", print_binary},
		{"u", print_unsigned_integer},
		{"o", print_octal},
		{"x", print_hex},
		{"S", print_String},
		{"p", print_pointer},
		{"X", print_HEX},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL},
	};
	va_list arguments;

	if (format == NULL)
		return (-1);

	va_start(arguments, format);
	chars = format_receiver(format, x_forms, arguments);
	va_end(arguments);
	return (chars);
}
