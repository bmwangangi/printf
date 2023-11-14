#include "main.h"

/* Print Unsigned Number */
/**
 * print_unsigned - Prints an unsigned number.
 * @args: List of arguments.
 * @trab: Buffer array for printing.
 * @evans: Flag calculations.
 * @diameter: Width specification.
 * @accurate: Precision specification.
 * @management: Size specifier.
 * Return: Number of characters printed.
 */
int print_unsigned(va_list args, char trab[],
	int evans, int diameter, int accurate, int management)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);

	num = convert_size_unsgnd(num, management);

	if (num == 0)
		trab[i--] = '0';

	trab[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		trab[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, trab, evans, diameter, accurate, management));
}

/* Print Octal Number */
/**
 * print_octal - Prints an unsigned number in octal notation.
 * @args: List of arguments.
 * @trab: Buffer array for printing.
 * @evans: Flag calculations.
 * @diameter: Width specification.
 * @accurate: Precision specification.
 * @management: Size specifier.
 * Return: Number of characters printed.
 */
int print_octal(va_list args, char trab[],
	int evans, int diameter, int accurate, int management)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(diameter);

	num = convert_size_unsgnd(num, management);

	if (num == 0)
		trab[i--] = '0';

	trab[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		trab[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (evans & F_HASH && init_num != 0)
		trab[i--] = '0';

	i++;

	return (write_unsgnd(0, i, trab, evans, diameter, accurate, management));
}

/* Print Hexadecimal Number */
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation.
 * @args: List of arguments.
 * @trab: Buffer array for printing.
 * @evans: Flag calculations.
 * @diameter: Width specification.
 * @accurate: Precision specification.
 * @management: Size specifier.
 * Return: Number of characters printed.
 */
int print_hexadecimal(va_list args, char trab[],
	int evans, int diameter, int accurate, int management)
{
	return (print_hexa(args, "0123456789abcdef", trab,
		evans, 'x', diameter, accurate, management));
}

/* Print Uppercase Hexadecimal Number */
/**
 * print_hexa_upper - Prints an unsigned number in uppercase hexadecimal notation.
 * @args: List of arguments.
 * @trab: Buffer array for printing.
 * @evans: Flag calculations.
 * @diameter: Width specification.
 * @accurate: Precision specification.
 * @management: Size specifier.
 * Return: Number of characters printed.
 */
int print_hexa_upper(va_list args, char trab[],
	int evans, int diameter, int accurate, int management)
{
	return (print_hexa(args, "0123456789ABCDEF", trab,
		evans, 'X', diameter, accurate, management));
}

/* Print Hexadecimal Number (Lower/Upper) */
/**
 * print_hexa - Prints a hexadecimal number in lower or uppercase.
 * @args: List of arguments.
 * @map_to: Array for mapping the number to.
 * @trab: Buffer array for printing.
 * @evans: Flag calculations.
 * @flag_ch: Flag character.
 * @diameter: Width specification.
 * @accurate: Precision specification.
 * @management: Size specifier.
 * @size: Size specification.
 * Return: Number of characters printed.
 */
int print_hexa(va_list args, char map_to[], char trab[],
	int evans, char flag_ch, int diameter, int accurate, int management)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(diameter);

	num = convert_size_unsgnd(num, management);

	if (num == 0)
		trab[i--] = '0';

	trab[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		trab[i--] = map_to[num % 16];
		num /= 16;
	}

	if (evans & F_HASH && init_num != 0)
	{
		trab[i--] = flag_ch;
		trab[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, trab, evans, diameter, accurate, management));
}

