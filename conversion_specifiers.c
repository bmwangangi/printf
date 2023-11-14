#include "main.h"

/**
 * print_chararacter - Prints a character
 * @args: List of arguments
 * @trab: Buffer array to handle print
 * @evans: Used to calculate active flags
 * @diameter: Diameter
 * @accurate: Accurate specification
 * @measurement: Measurement specifier
 *
 * Return: Number of characters printed
 */
int print_chararacter(va_list args, char trab[],
                      int evans, int diameter, int accurate, int measurement)
{
    char a = va_arg(args, int);
    return (handling__char(a, trab, evans, diameter, accurate, measurement));
}

/**
 * print_string - Prints a string
 * @args: List of arguments
 * @trab: Buffer array to handle print
 * @evans: Used to calculate active data type evans
 * @diameter: Used to get diameter
 * @accurate: Accurate
 * @measurement: Measurement specifier
 *
 * Return: Number of characters printed
 */
int print_string(va_list args, char trab[],
                 int evans, int diameter, int accurate, int measurement)
{
    int len = 0, b;
    char *string = va_arg(args, char *);

    UNUSED(trab);
    UNUSED(evans);
    UNUSED(diameter);
    UNUSED(accurate);
    UNUSED(measurement);

    if (string == NULL)
    {
        string = "(null)";
        if (accurate >= 6)
            string = "      ";
    }

    while (string[len] != '\0')
        len++;

    if (accurate >= 0 && accurate < len)
    {
        if (evans & F_MINUS)
        {
            write(1, &string[0], len);
            for (b = diameter - len; b > 0; b--)
                write(1, " ", 1);
            return (diameter);
        }
        else
        {
            for (b = diameter - len; b > 0; b--)
                write(1, " ", 1);
            write(1, &string[0], len);
            return (diameter);
        }
    }

    return (write(1, string, len));
}

/**
 * print_the_percent - Prints a percent sign
 * @args: List of arguments
 * @trab: Array to handle print
 * @evans: Calculates active data
 * @diameter: Diameter
 * @accurate: Accurate
 * @measurement: Measurement specifier
 *
 * Return: Number of characters printed
 */
int print_the_percent(va_list args, char trab[],
                      int evans, int diameter, int accurate, int measurement)
{
    UNUSED(args);
    UNUSED(trab);
    UNUSED(evans);
    UNUSED(diameter);
    UNUSED(accurate);
    UNUSED(measurement);

    return (write(1, "%%", 1));
}

/**
 * print_integer - Print an integer
 * @args: List of arguments
 * @trab: Array to handle print
 * @evans: Calculates active data
 * @diameter: Get the diameter
 * @accurate: Accurate specification
 * @measurement: Measurement specifier
 *
 * Return: Number of characters printed
 */
int print_integer(va_list args, char trab[],
                  int evans, int diameter, int accurate, int measurement)
{
    int c = BUFF_SIZE - 2;
    int is_negative = 0;
    long int m = va_arg(args, long int);
    unsigned long int num;

    m = convert_size_number(m, measurement);

    if (m == 0)
        buffer[c--] = '0';

    buffer[BUFF_SIZE - 1] = '\0';
    num = (unsigned long int)m;

    if (m < 0)
    {
        num = (unsigned long int)((-1) * m);
        is_negative = 1;
    }

    while (num > 0)
    {
        buffer[c--] = (num % 10) + '0';
        num /= 10;
    }

    if (is_negative)
        buffer[c--] = '-';

    return (handling__integer(buffer + c + 1, trab, evans, diameter, accurate, measurement));
}

/**
 * print_binary_form - Prints the binary form of an unsigned integer
 * @args: List of arguments
 * @trab: Array to handle print
 * @evans: Calculates active data
 * @diameter: Diameter
 * @accurate: Accurate
 * @measurement: Measurement specifier
 *
 * Return: Number of characters printed
 */
int print_binary_form(va_list args, char trab[],
                      int evans, int diameter, int accurate, int measurement)
{
    unsigned int b, c, d, sum;
    unsigned int x[32];
    int counting;

    UNUSED(trab);
    UNUSED(evans);
    UNUSED(diameter);
    UNUSED(accurate);
    UNUSED(measurement);

    b = va_arg(args, unsigned int);
    c = 2147483648; /* (2 ^ 31) */
    x[0] = b / c;
    for (d = 1; d < 32; d++)
    {
        c /= 2;
        x[d] = (b / c) % 2;
    }
    for (d = 0, sum = 0, counting = 0; d < 32; d++)
    {
        sum += x[d];
        if (sum || d == 31)
        {
            char s = '0' + x[d];
            write(1, &s, 1);
            counting++;
        }
    }
    return (counting);
}

