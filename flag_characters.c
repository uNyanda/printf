#include "main.h"

/**
 * plus_flag - Handles the '+' flag.
 *
 * @data: A pointer to an arg_data_t struct.
 *
 * This function sets the PLUS_FLAG bit in the flags field of the arg_data_t
 * struct, indicating that the '+' flag is active.
 */
void plus_flag(arg_data_t *data)
{
	data->flags |= PLUS_FLAG;
}

/**
 * space_flag - Handles the ' ' (space) flag.
 *
 * @data: A pointer to an arg_data_t struct.
 *
 * This function sets the SPACE_FLAG bit in the flags field of the arg_data_t
 * struct, indicating that the ' ' (space) flag is active.
 */
void space_flag(arg_data_t *data)
{
	data->flags |= SPACE_FLAG;
}

/**
 * hash_flag - Handles the '#' flag.
 *
 * @data: A pointer to an arg_data_t struct.
 *
 * This function sets the HASH_FLAG bit in the flags field of the arg_data_t
 * struct, indicating that the '#' flag is active.
 */
void hash_flag(arg_data_t *data)
{
	data->flags |= HASH_FLAG;
}

/**
 * zero_flag - Handles the '0' flag.
 *
 * @data: A pointer to an arg_data_t struct.
 *
 * This function sets the ZERO_FLAG bit in the flags field of the arg_data_t
 * struct, indicating that the '0' flag is active.
 */
void zero_flag(arg_data_t *data)
{
	data->flags |= ZERO_FLAG;
}

/**
 * init_flags - Initializes an array of flag_t structs.
 *
 * Return: A pointer to the first element in the array of flag_t structs.
 *
 * This function initializes a static array of flag_t structs, each containing
 * a flag character and a pointer to the corresponding flag handling function.
 * It returns a pointer to the first element in the array.
 */
flag_t *init_flags(void)
{
	static flag_t flags[] = {
		{'+', plus_flag},
		{' ', space_flag},
		{'#', hash_flag},
		{'0', zero_flag},
		{'\0', NULL}
	};

	return (flags);
}
