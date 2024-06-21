#include "main.h"

/**
 * int_to_str - Converts an integer to a string.
 *
 * @num: A pointer to the integer to be converted.
 * @str: A pointer to the current position in the buffer.
 * @count: A pointer to the count of characters added to the buffer.
 * @is_negative: An integer indicating whether the number is negative.
 *
 * This function converts an integer to a string by repeatedly dividing
 * the number by 10 and adding the remainder to the buffer. It handles
 * negative numbers by negating the remainder before adding it to the buffer.
 */
void int_to_str(int *num, char **str, int *count, int is_negative)
{
	do {
		(*str)--;
		/* handle negative numbers manually */
		**str = '0' + (is_negative ? -(*num % 10) : (*num % 10));
		*num /= 10;
		(*count)++;
	} while (*num != 0);
}

/**
 * handle_int_flags - Handles the '+' (plus), ' ' (space),
 * and '-' (minus) flags.
 *
 * @is_negative: An integer indicating whether the number is negative.
 * @str: A pointer to the current position in the buffer.
 * @count: A pointer to the count of characters added to the buffer.
 * @data: A pointer to an arg_data_t structure.
 *
 * This function checks the flags in the arg_data_t structure and adds the
 * appropriate character to the buffer if a flag is set. It increments the
 * count for each character added to the buffer.
 */
void handle_int_flags(int is_negative, char **str, int *count,
arg_data_t *data)
{
	if (is_negative)
	{
		(*str)--;
		**str = '-';
		(*count)++;
	}
	else if ((data->flags & PLUS_FLAG))
	{
		(*str)--;
		**str = '+';
		(*count)++;
	}
	else if ((data->flags & SPACE_FLAG))
	{
		(*str)--;
		**str = ' ';
		(*count)++;
	}
}
