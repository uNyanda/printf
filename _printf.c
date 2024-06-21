#include "main.h"

/**
 * _printf - A custom implementation of the printf function.
 *
 * @format: The format string that specifies how subsequent arguments are
 * converted for output.
 *
 * This function takes a format string and a variable number of arguments,
 * initializes an arg_data_t struct and an array of specifier_t structs, and
 * processes the format string. If the format string is NULL, it returns -1.
 * It uses the process_format_string function to process the format string and
 * update the count of printed characters in the arg_data_t struct.If the count
 * is -1 after processing the format string, it returns -1. Otherwise, it ends
 * the va_list in the arg_data_t struct and returns the count of printed
 * characters.
 *
 * Return: The total count of printed characters if the format string is
 * processed successfully, -1 otherwise.
*/
int _printf(const char *format, ...)
{
	arg_data_t data;
	specifier_t *specifiers = init_specifiers();
	flag_t *flags = init_flags();

	va_start(data.args, format);
	data.count = 0;
	data.i = 0;
	data.flags = 0;

	if (format == NULL)
	{
		return (-1);
	}

	process_format_string(format, specifiers, flags, &data);

	if (data.count == -1)
	{
		return (-1);
	}

	va_end(data.args);

	flush_buffer(&data); /* flush the buffer */

	return (data.count);
}
