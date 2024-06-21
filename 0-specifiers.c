#include "main.h"

/**
 * print_char - A function that prints a character.
 *
 * @data: A pointer to an arg_data_t struct.
 *
 * This function retrieves a character from the va_list in the arg_data_t
 * struct, prints it, increments the count of printed characters in the struct
 * and returns the count.
 *
 * Return: The total count of printed characters after the function call.
*/
int print_char(arg_data_t *data)
{
	char c = (char)va_arg(data->args, int);

	_putchar(c, data);
	data->count++;

	return (data->count);
}

/**
 * print_string - A function that prints a string.
 *
 * @data: A pointer to an arg_data_t struct.
 *
 * This function retrieves a string from the va_list in the arg_data_t struct,
 * prints it character by character, increments the count of printed characters
 * in the struct, and returns the count. If the string is NULL, it prints
 * "(null)".
 *
 * Return: The total count of printed characters after the function call.
*/
int print_string(arg_data_t *data)
{
	char *str = va_arg(data->args, char *);
	int count = 0;

	if (str == NULL)
	{
		str = "(null)";
	}

	while (*str)
	{
		_putchar(*str, data);
		str++;
		count++;
	}
	data->count += count;

	return (data->count);
}

/**
 * print_percent - A function that prints a percent sign.
 *
 * @data: A pointer to an arg_data_t struct. This paramenter is not used in the
 * function.
 *
 * This function prints a percent sign and returns the result of the print op.
 *
 * Return: The result of the print operation.
*/
int print_percent(arg_data_t *data)
{
	(void)data;

	_putchar('%', data);
	data->count++;

	return (data->count);
}

/**
 * print_int - A function that prints an integer.
 *
 * @data: A pointer to an arg_data_t struct.
 *
 * This function retrieves an integer from the va_list in the arg_data_t
 * struct, converts it to a string, prints it character by character,
 * increments the count of printed characters in the struct, and returns the
 * count.
 *
 * Return: The total count of printed characters after the function call.
*/
int print_int(arg_data_t *data)
{
	int num = va_arg(data->args, int);
	char buffer[12];  /* Buffer to hold the string repres. of the integer */
	char *str = &buffer[11];  /* Start from the end of the buffer */
	int count = 0;
	int is_negative = 0;

	*str = '\0';  /* Null-terminate the string */
	if (num < 0)
	{
		is_negative = 1;
	}
	/* Convert the integer to a string */
	int_to_str(&num, &str, &count, is_negative);
	handle_int_flags(is_negative, &str, &count, data);

	while (*str)
	{
		_putchar(*str, data);
		str++;
	}
	data->count += count;
	return (data->count);
}

/**
 * print_binary - A function that prints an unsigned int as binary.
 *
 * @data: A pointer to an arg_data_t struct.
 *
 * This function retrieves an unsigned int from the va_list in the arg_data_t
 * struct, converts it to binary, prints it, increments the count of printed
 * characters in the struct, and returns the count.
 *
 * Return: The total count of printed characters after the function call.
*/
int print_binary(arg_data_t *data)
{
	unsigned int num = va_arg(data->args, unsigned int);
	char buffer[33];  /* Buffer to hold the binary repres. of the number */
	char *str = &buffer[32];  /* Start from the end of the buffer */
	int count = 0;

	*str = '\0';  /* Null-terminate the string */

	/* Convert the number to binary */
	do {
		str--;
		*str = '0' + (num % 2);
		num /= 2;
		count++;
	} while (num != 0);

	/* Print the binary representation and update the count */
	while (*str)
	{
		_putchar(*str, data);
		str++;
	}
	data->count += count;

	return (data->count);
}
