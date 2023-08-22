#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints the unsigned number
 * @types: List arguments
 * @buffer: The buffer array to handle the print
 * @flags:  Calculates the active flags
 * @width: The width
 * @precision: The precision of specification
 * @size: Size of specifier
 * Return: Number of characters printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/*********** PRINT UNSIGNED NUMBER IN OCTAL  **************/
/**
 * print_octal - Prints an unsigned number in the octal notation
 * @types: List arguments
 * @buffer: The buffer array to handle the print
 * @flags:  Calculates active the flags
 * @width: The width
 * @precision: The precision of specification
 * @size: Size of specifier
 * Return: Number of characters printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************ PRINT UNSIGNED NUMBER IN HEXADECIMAL ************/
/**
 * print_hexadecimal - Prints an unsigned number in the hexadecimal notation
 * @types: List arguments
 * @buffer: The buffer array to handle the print
 * @flags:  Calculates the active flags
 * @width: The width
 * @precision: The precision of specification
 * @size: Size of specifier
 * Return: Number of characters printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/*********** PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL ************/
/**
 * print_hexa_upper - Prints unsigned number in the upper hexadecimal notation
 * @types: List arguments
 * @buffer: The buffer array to handle the print
 * @flags:  Calculates the active flags
 * @width: The width
 * @precision: The precision of specification
 * @size: Size of specifier
 * Return: Number of characters printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************ PRINT HEXX NUM IN LOWER OR UPPER ************/
/**
 * print_hexa - Print the hexadecimal number in a lower or upper
 * @types: List arguments
 * @map_to: Array of the values to map the number
 * @buffer: The buuffer array to handle the print
 * @flags:  Calculates the active flags
 * @flag_ch: Cal. active flags
 * @width: The width
 * @precision: The precision of specification
 * @size: Size of specifier
 * @size: Size of specification
 * Return: Number of characters printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
