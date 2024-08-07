# 0x11. C - Printf

## In this project, we built our custom `_printf` function as part of our low level programming

> [!NOTE]
> As part of this project, we were not allowed to use the standard library, only authorized functions.

### Authorized functions and macros

- `write` (`man 2 write`)
- `malloc` (`man 3 malloc`)
- `free` (`man 3 free`)
- `va_start` (`man 3 va_start`)
- `va_end` (`man 3 va_end`)
- `va_copy` (`man 3 va_copy`)
- `va_arg` (`man 3 va_arg`)

### Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c
```

**All test files including `main` functions are in the [tests](tests/) folder.**

<table>
  <tr>
    <th colspan="2" style="text-align:center;">CUSTOM CONVERSION SPECIFIERS</th>
  </tr>
  <tr>
    <td style="text-align:center;"><code>b</code></td>
    <td>the unsigned int argument is converted to binary</td>
  </tr>
  <tr>
    <td style="text-align:center;"><code>S</code></td>
    <td>prints the string.<br>&emsp;<ul><li>Non-printable characters (0 < ASCII value < 32 or >= 127 are printed this way: <code>\x</code>, followed by the ASCII code value in hexadecimal (upper case - always 2 characters))</li></ul></td>
  </tr>
  <tr>
    <td style="text-align:center;"><code>r</code></td>
    <td>prints the reversed string.</td>
  </tr>
  <tr>
    <td style="text-align:center;"><code>R</code></td>
    <td>prints the rot13'ed string</td>
  </tr>
  <tr>
    <th colspan="2" style="text-align:center;">STANDARD CONVERSION SPECIFIERS</th>
  </tr>
</table>
