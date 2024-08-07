#include "main.h"

/**
 * handle_flags - Handles the '+' (plus), ' ' (space), '#' (hash), and
 * '0' (zero) flags.
 * @format: A pointer to the current position in the format string.
 * @flags: A pointer to an array of flag_t structs, each containing a flag
 *         character and a pointer to a function that handles that flag.
 * @data: A pointer to an arg_data_t structure.
 *
 * This function checks if the current character in the format string is a
 * flag. If it is, the function calls the corresponding flag handling function
 * to set the appropriate flag in the data->flags field, and increments the
 * format pointer to move past the flag.
 */
void handle_flags(const char **format, flag_t *flags, arg_data_t *data)
{
	int i;
	int found_flag;

	do {
		found_flag = 0;
		for (i = 0; flags[i].flag; i++)
		{
			if (flags[i].flag == **format)
			{
				flags[i].f(data);
				(*format)++;
				found_flag = 1;
				break;
			}
		}
	} while (found_flag);
}

/**
 * handle_specifiers - Handles the specifiers in the format string.
 * @format: A pointer to the current position in the format string.
 * @specifiers: A pointer to an array of specifier_t structures.
 * @data: A pointer to an arg_data_t structure.
 *
 * This function checks if the current character in the format string is a
 * specifier.
 * If it is, the function calls the corresponding function in the specifiers
 * array.
 * If no match is found, the function adds the '%' and the unknown character
 * to the buffer.
 *
 * Return: integer.
 */
int handle_specifiers(const char **format, specifier_t *specifiers,
arg_data_t *data)
{
	int i;
	length_modifier_t *length_modifiers = init_length_modifiers();

	for (i = 0; length_modifiers[i].modifier; i++)
	{
		if (_strcmp(*format, length_modifiers[i].modifier) == 0)
		{
			data->length_modifier =
				length_modifiers[i].modifier[0];
			(*format) += _strlen(length_modifiers[i].modifier);
			break;
		}
	}

	for (i = 0; specifiers[i].spec; i++)
	{
		if (specifiers[i].spec == **format)
		{
			specifiers[i].f(data);
			break;
		}
	}
	return (i);
}
