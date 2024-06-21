#include "main.h"

/**
 * print_unsigned - A function that prints an unsigned int as decimal.
 *
 * @data: A pointer to an arg_data_t struct.
 *
 * This function retrieves an unsigned int from the va_list in the arg_data_t
 * struct, converts it to a string, prints it, increments the count of printed
 * characters in the struct, and returns the count.
 *
 * Return: The total count of printed characters after the function call.
*/
int print_unsigned(arg_data_t *data)
{
	unsigned int num = va_arg(data->args, unsigned int);
	char buffer[11];  /* Buffer to hold the string repres. of the number */
	char *str = &buffer[10];  /* Start from the end of the buffer */
	int count = 0;

	*str = '\0';  /* Null-terminate the string */

	/* Convert the number to a string */
	do {
		str--;
		*str = '0' + (num % 10);
		num /= 10;
		count++;
	} while (num != 0);

	if (data->flags & 2) /* if the 'space' flag is set */
	{
		str--;
		*str = ' ';
		count++;
	}

	/* Print the string and update the count */
	while (*str)
	{
		_putchar(*str, data);
		str++;
	}
	data->count += count;

	return (data->count);
}

/**
 * print_octal - A function that prints an unsigned int as octal.
 *
 * @data: A pointer to an arg_data_t struct.
 *
 * This function retrieves an unsigned int from the va_list in the arg_data_t
 * struct, converts it to an octal string, prints it, increments the count of
 * printed characters in the struct, and returns the count.
 *
 * Return: The total count of printed characters after the function call.
*/
int print_octal(arg_data_t *data)
{
	unsigned int num = va_arg(data->args, unsigned int);
	unsigned int og_num = num; /* store the original number*/
	char buffer[12];  /* Buffer to hold the octal repres. of the number */
	char *str = &buffer[11];  /* Start from the end of the buffer */
	int count = 0;

	*str = '\0';  /* Null-terminate the string */

	/* Convert the number to octal */
	do {
		str--;
		*str = '0' + (num % 8);
		num /= 8;
		count++;
	} while (num != 0);

	if (og_num != 0 && (data->flags & 4)) /* if the '#' flag is set */
	{
		str--;
		*str = '0';
		count++;
	}
	/* Print the octal representation and update the count */
	while (*str)
	{
		_putchar(*str, data);
		str++;
	}
	data->count += count;

	return (data->count);
}

/**
 * print_hex_lower - A function that prints an unsigned int as hexadecimal
 * (lowercase).
 *
 * @data: A pointer to an arg_data_t struct.
 *
 * This function retrieves an unsigned int from the va_list in the arg_data_t
 * struct, converts it to a lowercase hexadecimal string, prints it, increments
 * the count of printed characters in the struct, and returns the count.
 *
 * Return: The total count of printed characters after the function call.
*/
int print_hex_lower(arg_data_t *data)
{
	unsigned int num = va_arg(data->args, unsigned int);
	unsigned int og_num = num; /* store the original number */
	char buffer[9];  /* Buffer to hold the hexadecimal repres. of the number */
	char *str = &buffer[8];  /* Start from the end of the buffer */
	int count = 0;

	*str = '\0';  /* Null-terminate the string */

	/* Convert the number to hexadecimal */
	do {
		str--;
		*str = "0123456789abcdef"[num % 16];
		num /= 16;
		count++;
	} while (num != 0);

	if (og_num != 0 && (data->flags & 4)) /* if the '#' flag is set */
	{
		str -= 2;
		*str = '0';
		*(str + 1) = 'x';
		count += 2;
	}
	/* Print the hexadecimal representation and update the count */
	while (*str)
	{
		_putchar(*str, data);
		str++;
	}
	data->count += count;
	return (data->count);
}

/**
 * print_hex_upper - A function that prints an unsigned int as hexadecimal
 * (uppercase).
 *
 * @data: A pointer to an arg_data_t struct.
 *
 * This function retrieves an unsigned int from the va_list in the arg_data_t
 * struct, converts it 2 an uppercase hexadecimal string, prints it, increments
 * the count of printed characters in the struct, and returns the count.
 *
 * Return: The total count of printed characters after the function call.
*/
int print_hex_upper(arg_data_t *data)
{
	unsigned int num = va_arg(data->args, unsigned int);
	unsigned int og_num = num; /* store the original number */
	char buffer[9];  /* Buffer to hold the hexadecimal repres. of the number */
	char *str = &buffer[8];  /* Start from the end of the buffer */
	int count = 0;

	*str = '\0';  /* Null-terminate the string */

	/* Convert the number to hexadecimal */
	do {
		str--;
		*str = "0123456789ABCDEF"[num % 16];
		num /= 16;
		count++;
	} while (num != 0);

	if (og_num != 0 && (data->flags & 4)) /* if the '#' flag is set */
	{
		str -= 2;
		*str = '0';
		*(str + 1) = 'X';
		count += 2;
	}
	/* Print the hexadecimal representation and update the count */
	while (*str)
	{
		_putchar(*str, data);
		str++;
	}
	data->count += count;

	return (data->count);
}

/**
 * print_string_S - Prints a string with special characters displayed in
 * hexadecimal.
 * @data: A pointer to an arg_data_t structure.
 *
 * Return: The total count of characters printed.
 */
int print_string_S(arg_data_t *data)
{
	char *str = va_arg(data->args, char *);
	int count = 0;

	if (str == NULL)
	{
		str = "(null)";
	}

	while (*str)
	{
		if (*str < 32 || *str >= 127)
		{
			_putchar('\\', data);
			_putchar('x', data);
			_putchar("0123456789ABCDEF"[(*str >> 4) & 0xF], data);
			_putchar("0123456789ABCDEF"[*str & 0xF], data);
			count += 4;
		}
		else
		{
			_putchar(*str, data);
			count++;
		}
		str++;
	}
	data->count += count;

	return (data->count);
}
