<h1 style="text-align: center; color: white"> 0x11. C - Printf</h1>

## In this project, we built our custom printf function as part of our low level programming

> [!NOTE]
> As part of this project, we were not allowed to use the standard library, only authorized functions.

### Authorized functions and macros

- <code style="color: grey;">write</code> (`man 2 write`)
- <code><span style="color: grey;">malloc</span></code> (`man 3 malloc`)
- <code><span style="color: grey;">free</span></code> (`man 3 free`)
- <code><span style="color: grey;">va_start</span></code> (`man 3 va_start`)
- <code><span style="color: grey;">va_end</span></code> (`man 3 va_end`)
- <code><span style="color: grey;">va_copy</span></code> (`man 3 va_copy`)
- <code><span style="color: grey;">va_arg</span></code> (`man 3 va_arg`)

### Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c
```

> [!IMPORTANT]
> Use the flag <code><span style="color: blue;"><i>-Wno-format</i></span></code> when testing <code><span style="color: red;">_printf</span></code> and the standard <code><span style="color: green;">printf</span></code>

**All test files including `main` functions are in the [tests](tests/) folder.**

<table>
  <tr>
    <th colspan="2" style="text-align:center;">CUSTOM CONVERSION SPECIFIERS</th>
  </tr>
  <tr>
    <td style="text-align:center;"><code><span style="color: red;">b</span></code></td>
    <td>the unsigned integer argument is converted to binary</td>
  </tr>
  <tr>
    <td style="text-align:center;"><code><span style="color: red;">S</span></code></td>
    <td>prints the string<br><ul><li>Non-printable characters (0 < ASCII value < 32 or >= 127 are printed this way: <code>\x</code>, followed by the ASCII code value in hexadecimal (upper case - always 2 characters))</li></ul></td>
  </tr>
  <tr>
    <td style="text-align:center;"><code><span style="color: red;">r</span></code></td>
    <td>prints the reversed string</td>
  </tr>
  <tr>
    <td style="text-align:center;"><code><span style="color: red;">R</span></code></td>
    <td>prints the rot13'ed string</td>
  </tr>
  <tr>
    <th colspan="2" style="text-align:center;">STANDARD CONVERSION SPECIFIERS</th>
  </tr>
  <tr>
    <td style="text-align:center;"><code><span style="color: green;">c</span></code></td>
    <td>formats a single character</td>
  </tr>
  <tr>
    <td style="text-align:center;"><code><span style="color: green;">s</span></code></td>
    <td>formats a string</td>
  </tr>
  <tr>
    <td style="text-align:center;"><code><span style="color: green;">%</span></code></td>
    <td>prints a literal percent sign</td>
  </tr>
  <tr>
    <td style="text-align:center;"><code><span style="color: green;">d</span></code></td>
    <td>formats a signed integer in decimal (base 10) notation</td>
  </tr>
  <tr>
    <td style="text-align:center;"><code><span style="color: green;">i</span></code></td>
    <td>formats a signed integer in decimal (base 10) notation</td>
  </tr>
  <tr>
    <td style="text-align:center;"><code><span style="color: green;">u</span></td>
    <td>formats an unsigned integer in decimal (base 10) notation</td>
  </tr>
  <tr>
    <td style="text-align:center;"><code><span style="color: green;">o</span></td>
    <td>formats an integer in octal (base 8) notation</td>
  </tr>
  <tr>
    <td style="text-align:center;"><code><span style="color: green;">x</span></td>
    <td>formats an integer in hexadecimal (base 16) notation using lowercase letters (a through f)</td>
  </tr>
  <tr>
    <td style="text-align:center;"><code><span style="color: green;">X</span></td>
    <td>formats an integer in hexadecimal (base 16) notation using uppercase letters (A through F)</td>
  </tr>
  <tr>
    <td style="text-align:center;"><code><span style="color: green;">p</span></td>
    <td>formats a pointer (address)</td>
  </tr>
</table>

**The non-custom/standard conversion specifiers can only handle:**

- flag characters (<span style="color: brown;"><strong>+</strong></span>, <span style="color: brown;"><strong>space</strong></span>, <span style="color: brown;"><strong>#</strong></span>, <span style="color: brown;">0</strong></span>, <span style="color: brown;"><strong>-</strong></span>)
- length modifiers (<span style="color: brown;"><strong>l</strong></span>, <span style="color: brown;"><strong>h</strong></span>)
- field width
- precision

### Usage

```c
  _printf("%b\n", 98);
  _printf("%R\n", "Hello, World!");
  _printf("%S\n", "Best\nSchool");
  _printf("%r\n", "!dlroW ,olleH");
```
