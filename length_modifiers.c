#include "main.h"

/**
 * handle_long - function handles 'long' length modifier.
 *
 * @data:
 * @args:
 */
void handle_long(arg_data_t *data, va_list args)
{
	long arg = va_arg(args, long);
}

/**
 * handle_short - function handles 'short' length modifier.
 *
 * @data:
 * @args:
 */
void handle_short(arg_data_t *data, va_list args)
{
	short arg = (short)va_arg(args, int);
}

/**
 * init_length_modifiers -
 */
length_modifier_t *init_length_modifiers(void)
{
	static length_modifier_t length_modifiers[] = {
		{"l", handle_long},
		{"h", handle_short},
		{NULL, NULL}
	};

	return (length_modifiers);
}

/**
 * _strlen - function returns the length of a string.
 *
 * @s: pointer to a string to return length of.
 *
 * Return: the length of the string.
 */
int _strlen(const char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * _strcmp - function compares two strings.
 *
 * @s1: pointer to the first string.
 * @s2: pointer to the second string.
 *
 * Return:
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}
