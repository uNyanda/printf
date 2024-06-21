#include <stdio.h>
#include "../main.h"

/* Assume _printf and related functions are defined here */

int main(void)
{
    char *test_string = "Hello, World!";

    _printf("%R\n", test_string);

    return 0;
}
