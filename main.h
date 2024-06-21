#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>

#define print_decimal print_int /* replaces print_decimal with print_int */
#define BUFFER_SIZE 1024 /* for the 'write' buffer */

#define PLUS_FLAG 1
#define SPACE_FLAG 2
#define HASH_FLAG 4
#define ZERO_FLAG 8

/**
 * struct arg_data - A struct for storing argument data.
 *
 * @args: A va_list containing the arguments to be processed.
 * @count: An integer representing the count of arguments.
 * @buffer: A character array used as a buffer to store characters before they
 * are written to the standard output.
 * @i: An integer representing the index of the next free position in the
 * buffer.
 * @flags: An integer used to store the state of various flags that affect
 * the behavior of the printf function. Each bit in the integer represents
 * a different flag. For example, you could use one bit to represent the '#'
 * flag, another bit to represent the '0' flag, and so on.
 * @length_modifier: 
*/
typedef struct arg_data
{
	va_list args;
	int count;
	char buffer[BUFFER_SIZE];
	int i;
	int flags;
	char length_modifier;
} arg_data_t;

/**
 * struct specifier - A struct for storing a specifier and its corresponding
 *					function.
 *
 * @spec: A character representing the specifier.
 * @f: A pointer to a function that takes an arg_data_t pointer and returns an
 *		integer.
*/
typedef struct specifier
{
	char spec;
	int (*f)(arg_data_t *);
} specifier_t;

/**
 * struct flag - A struct for storing a flag character and its corresponding
 *               function.
 *
 * @flag: A character representing the flag.
 * @f: A pointer to a function that takes an arg_data_t pointer and modifies
 *     it according to the flag.
 */
typedef struct flag
{
	char flag;
	void (*f)(arg_data_t *);
} flag_t;

/**
 * struct length_modifier - A struct for storing length modifiers and their
 *                         corresponding functions.
 *
 * @modifier: a pointer to the modifier.
 * @f: a pointer to a function that takes an arg_data_t and va_list.
 */
typedef struct length_modifier {
	char *modifier;
	void (*f)(arg_data_t *, va_list);
} length_modifier_t;

/* 0-helper_functions.c */
int _putchar(char c, arg_data_t *data);
specifier_t *init_specifiers(void);
void handle_percent(const char **format, specifier_t *specifiers,
flag_t *flags, arg_data_t *data);
void process_format_string(const char *format, specifier_t *specifiers,
flag_t *flags, arg_data_t *data);
void flush_buffer(arg_data_t *data);

/* 1-helper_functions.c */
void handle_flags(const char **format, flag_t *flags, arg_data_t *data);
int handle_specifiers(const char **format, specifier_t *specifiers,
arg_data_t *data);

/* 0-specifier_helper_functions.c */
void int_to_str(int *num, char **str, int *count, int is_negative);
void handle_int_flags(int is_negative, char **str, int *count,
arg_data_t *data);

/* 0-specifiers.c */
int print_char(arg_data_t *data);
int print_string(arg_data_t *data);
int print_percent(arg_data_t *data);
int print_int(arg_data_t *data);
int print_binary(arg_data_t *data);

/* 1-specifiers.c */
int print_unsigned(arg_data_t *data);
int print_octal(arg_data_t *data);
int print_hex_lower(arg_data_t *data);
int print_hex_upper(arg_data_t *data);
int print_string_S(arg_data_t *data);

/* 2-specifiers.c */
int print_pointer(arg_data_t *data);
int print_reverse(arg_data_t *data);
int print_rot13(arg_data_t *data);

/* flag_characters.c */
void plus_flag(arg_data_t *data);
void space_flag(arg_data_t *data);
void hash_flag(arg_data_t *data);
void zero_flag(arg_data_t *data);
flag_t *init_flags(void);

/* length_modifiers.c */
void handle_long(arg_data_t *data, va_list args);
void handle_short(arg_data_t *data, va_list args);
length_modifier_t *init_length_modifiers(void);
int _strlen(const char *s);
int _strcmp(const char *s1, const char *s2);

/* _printf.c */
int _printf(const char *format, ...);

#endif
