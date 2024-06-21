#include "main.h"

/**
 * _putchar - A function that writes a character to the output BUFFER.
 *
 * @c: The character to be written.
 * @data: a pointer to the arg_data_t struct.
 *
 * This function writes a character to the output buffer using the
 * write system call.
 *
 * Return: The number of characters written.
 * It should be 1 on success and -1 on error.
*/
int _putchar(char c, arg_data_t *data)
{

	if (data->i >= BUFFER_SIZE) /* if the buffer is full, flush it */
	{
		write(1, data->buffer, data->i);
		data->i = 0;
	}

	data->buffer[data->i] = c;
	data->i++;

	return (1);
}

/**
 * init_specifiers - A function that initializes an array of specifier_t
 * structs.
 *
 * This function initializes a static array of specifier_t structs,
 * each containing a specifier character and a pointer to the corresponding
 * function. The array is terminated with a struct containing '\0' and NULL.
 *
 * Return: A pointer to the first element of the array of specifier_t structs.
*/
specifier_t *init_specifiers(void)
{
	static specifier_t specifiers[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'d', print_int},
		{'i', print_decimal},
		{'b', print_binary},
		{'u', print_unsigned},
		{'o', print_octal},
		{'x', print_hex_lower},
		{'X', print_hex_upper},
		{'S', print_string_S},
		{'p', print_pointer},
		{'r', print_reverse},
		{'R', print_rot13},
		{'\0', NULL}
	};

	return (specifiers);
}

/**
 * handle_percent - A helper function that handles the '%' character in the
 * format string.
 *
 * @format: A pointer to the current position in the format string.
 * @specifiers: An array of specifier_t structs.
 * @flags: An array of flag_t structs.
 * @data: A pointer to an arg_data_t struct.
 *
 * This function is called when a '%' character is encountered in the format
 * string. It checks the character following the '%' and determines how to
 * process it. If the following character is a flag ('+', ' ', '#', or '0'),
 * it calls the corresponding flag handling function and increments the
 * format pointer. If the following character matches a specifier in the
 * specifiers array, it calls the corresponding function. If the following
 * character is another '%', it prints a '%'. If the following character does
 * not match any specifier, it prints the '%' and the following character.
 * If the string ends after the '%', it sets the count in the arg_data_t struct
 * to -1.
 */
void handle_percent(const char **format, specifier_t *specifiers,
flag_t *flags, arg_data_t *data)
{
	int i;
	(*format)++;
	if (**format == '\0') /* if the string ends after the '%' */
	{
		data->count = -1;
		return;
	}
	if (**format == '%')
	{
		_putchar('%', data);
		data->count++;
	}
	else
	{
		while (**format == '+' || **format == ' ' || **format == '#' ||
		**format == '0')
		{
			handle_flags(format, flags, data);
		}
		i = handle_specifiers(format, specifiers, data);
		if (!specifiers[i].spec) /* if no matching spec is found */
		{
			_putchar('%', data); /* print the '%' character */
			_putchar(**format, data); /* print the unknown character */
			data->count += 2;
		}
	}
}

/**
 * process_format_string - A function that processes a format string.
 *
 * @format: The format string to be processed.
 * @specifiers: An array of specifier_t structs.
 * @flags: An array of flag_t structs.
 * @data: A pointer to an arg_data_t struct.
 *
 * This function processes a format string. When it encounters a '%', it checks
 * the following character to determine how to process it. If the following
 * character is a flag ('+', ' ', '#', or '0'), it calls the corresponding
 * flag handling function and increments the format pointer. If the following
 * character matches a specifier in the specifiers array, it calls the
 * corresponding function. If the following character is another '%', it prints
 * a '%'. If the following character does not match any specifier, it prints
 * the '%' and the following character.
 * For any other character, it simply prints the character.
 */
void process_format_string(const char *format, specifier_t *specifiers,
flag_t *flags, arg_data_t *data)
{

	while (*format)
	{
		if (*format == '%')
		{
			handle_percent(&format, specifiers, flags, data);
			if (data->count == -1)
			{
				break;
			}
		}
		else
		{
			_putchar(*format, data);
			data->count++;
		}
		format++;
	}
}

/**
 * flush_buffer - A function that flushes the buffer in an arg_data_t struct.
 *
 * @data: A pointer to an arg_data_t struct.
 *
 * This function checks if the buffer in the arg_data_t struct is not empty.
 * If it's not, the function writes the contents of the buffer to the standard
 * output using the write function, and then resets the index of the next free
 * position in the buffer to 0. This ensures that any remaining characters in
 * the buffer are written to the standard output.
 */
void flush_buffer(arg_data_t *data)
{
	if (data->i > 0) /* if the buffer is not empty, flush it */
	{
		write(1, data->buffer, data->i);
		data->i = 0;
	}
}
