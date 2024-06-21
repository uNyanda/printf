#include "main.h"

/**
 * print_pointer - Prints the hexadecimal representation of a pointer.
 * @data: A pointer to an arg_data_t structure.
 *
 * Return: The total count of characters printed.
 */
int print_pointer(arg_data_t *data)
{
	void *ptr = va_arg(data->args, void *);
	uintptr_t num = (uintptr_t)ptr;
	char buffer[21] = {0};  /* Buffer to hold the pointer representation */
	char *str = &buffer[20];  /* Start from the end of the buffer */
	int count = 0;

	if (ptr == NULL)
	{
		/* Special case for null pointers */
		_putchar('(', data);
		_putchar('n', data);
		_putchar('i', data);
		_putchar('l', data);
		_putchar(')', data);
		data->count += 5;
		return (data->count);
	}
	*str = '\0';  /* Null-terminate the string */
	/* Convert the pointer to hexadecimal */
	do {
		str--;
		*str = "0123456789abcdef"[num % 16];
		num /= 16;
	} while (num != 0);
	/* Add the '0x' prefix */
	str -= 2;
	*str = '0';
	*(str + 1) = 'x';
	/* Print the pointer representation and update the count */
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
 * print_reverse - Prints a string in reverse.
 * @data: A pointer to an arg_data_t structure.
 *
 * Return: The total count of characters printed.
 */
int print_reverse(arg_data_t *data)
{
	char *str = va_arg(data->args, char *);
	int len = 0;
	int count = 0;

	if (str == NULL)
	{
		str = "(null)";
	}

	/* Calculate the length of the string */
	while (str[len] != '\0')
	{
		len++;
	}

	/* Print the string in reverse */
	while (len > 0)
	{
		_putchar(str[len - 1], data);
		len--;
		count++;
	}
	data->count += count;

	return (data->count);
}

/**
 * print_rot13 - Prints a string using ROT13 cipher.
 * @data: A pointer to an arg_data_t structure.
 *
 * This function retrieves the next argument from the args list in the
 * arg_data_t structure as a string.
 * If the string is NULL, it sets the string to "(null)".
 *
 * The function then iterates over each character in the string. If the
 * character is a letter from 'A' to 'M' or 'a' to 'm', it prints the character
 * shifted 13 places forward in the alphabet. If the character is a letter from
 * 'N' to 'Z' or 'n' to 'z', it prints the character shifted 13 places backward
 * in the alphabet.
 * Otherwise, it prints the character as is.
 *
 * After all characters in the string have been processed, the function adds
 * the count of printed characters to data->count, which keeps track of the
 * total number of characters printed so far.
 *
 * Finally, the function flushes the buffer by printing a null character ('\0')
 * and returns the total count of characters printed.
 *
 * Return: The total count of characters printed.
 */
int print_rot13(arg_data_t *data)
{
	char *str = va_arg(data->args, char *);
	int count = 0;

	if (str == NULL)
	{
		str = "(null)";
	}

	while (*str)
	{
		if ((*str >= 'A' && *str <= 'M') || (*str >= 'a' && *str <= 'm'))
		{
			_putchar(*str + 13, data);
		}
		else if ((*str >= 'N' && *str <= 'Z') || (*str >= 'n' && *str <= 'z'))
		{
			_putchar(*str - 13, data);
		}
		else
		{
			_putchar(*str, data);
		}
		str++;
		count++;
	}
	data->count += count;

	return (data->count);
}
