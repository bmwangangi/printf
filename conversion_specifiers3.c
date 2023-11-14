#include "main.h"

/* print pointer */
/**
 * print_pointer - Prints the value of a pointer variable
 * @args: List of arguments
 * @trab: Buffer array to handle print
 * @evans: Calculates active flags
 * @diameter: get width
 * @accurate: Precision specification
 * @measurement: Size specifier
 * Return: Number of chars printed.
 */
int print_pointer(va_list args, char trab[], int evans, int diameter, int accurate, int measurement)
{
	char extra_char = 0, padding_char = ' ';
	int index = BUFF_SIZE - 2, length = 2, padding_start = 1; /* length=2, for '0x' */
	unsigned long num_addresses;
	char map_to[] = "0123456789abcdef";
	void *addresses = va_arg(args, void *);

	UNUSED(diameter);
	UNUSED(measurement);

	if (addresses == NULL)
		return (write(1, "(nil)", 5));

	trab[BUFF_SIZE - 1] = '\0';
	UNUSED(accurate);

	num_addresses = (unsigned long)addresses;

	while (num_addresses > 0)
	{
		trab[index--] = map_to[num_addresses % 16];
		num_addresses /= 16;
		length++;
	}

	if ((evans & F_ZERO) && !(evans & F_MINUS))
		padding_char = '0';
	if (evans & F_PLUS)
		extra_char = '+', length++;
	else if (evans & F_SPACE)
		extra_char = ' ', length++;

	index++;

	return (write_pointer(trab, index, length, diameter, evans, padding_char, extra_char, padding_start));
}

/* print non-printable */
/**
 * print_non_printable - Prints ASCII codes in hexadecimal of non-printable chars
 * @args: List of arguments
 * @trab: Buffer array to handle print
 * @evans: Calculates active flags
 * @diameter: get width
 * @accurate: Precision specification
 * @measurement: Size specifier
 * Return: Number of chars printed
 */
int print_non_printable(va_list args, char trab[], int evans, int diameter, int accurate, int measurement)
{
	int i = 0, offset = 0;
	char *str = va_arg(args, char *);

	UNUSED(evans);
	UNUSED(diameter);
	UNUSED(accurate);
	UNUSED(measurement);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			trab[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], trab, i + offset);

		i++;
	}

	trab[i + offset] = '\0';

	return (write(1, trab, i + offset));
}

/* print reverse */
/**
 * print_reverse - Prints reverse string.
 * @args: List of arguments
 * @trab: Buffer array to handle print
 * @evans: Calculates active flags
 * @diameter: get width
 * @accurate: Precision specification
 * @measurement: Size specifier
 * Return: Numbers of chars printed
 */

int print_reverse(va_list args, char trab[], int evans, int diameter, int accurate, int measurement)
{
	char *str;
	int i, count = 0;

	UNUSED(trab);
	UNUSED(evans);
	UNUSED(diameter);
	UNUSED(measurement);

	str = va_arg(args, char *);

	if (str == NULL)
	{
		UNUSED(accurate);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/* print a string in rot13 */
/**
 * print_rot13string - Print a string in ROT13.
 * @args: List of arguments
 * @trab: Buffer array to handle print
 * @evans: Calculates active flags
 * @diameter: get width
 * @accurate: Precision specification
 * @measurement: Size specifier
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list args, char trab[], int evans, int diameter, int accurate, int measurement)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(args, char *);
	UNUSED(trab);
	UNUSED(evans);
	UNUSED(diameter);
	UNUSED(accurate);
	UNUSED(measurement);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}

