#include <stdio.h>
#include "../main.h"
/* Assume _printf and related functions are defined here */

int main(void)
{
    char *test_string1 = "Hello, World!";
    char *test_string2 = "Hello\nWorld!";

    _printf("Reverse: %r\n", test_string1);
    _printf("String_S: %S\n", test_string2);

    return 0;
}
