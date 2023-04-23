#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * _print_char - Prints a character to stdout
 *
 * @args: A va_list of arguments containing a single int argument
 *
 * Return: The number of characters printed (always 1)
 *
 */
int _print_char(va_list args)
{
int c = va_arg(args, int);
putchar(c);
return (1);
}

/**
 * _print_string - Prints a string to stdout
 *
 * @args: A va_list of arguments containing a single const char * argument
 *
 * Return: The number of characters printed (excluding the null byte used to
 * end output to strings)
 *
 */
int _print_string(va_list args)
{
const char *s = va_arg(args, const char *);
int count = 0;

if (s == NULL)
s = "(null)";

while (*s)
{
putchar(*s);
s++;
count++;
}

return (count);
}

/**
 * _printf - Prints formatted output to stdout
 *
 * @format: Format string with zero or more directives
 * @...: Optional arguments to substitute in the format string
 *
 * Return: The number of characters printed (excluding the null byte used to
 * end output to strings), or -1 on error
 *
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;

if (format == NULL)
return (-1);

va_start(args, format);

while (*format)
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
count += _print_char(args);
break;
case 's':
count += _print_string(args);
break;
case '%':
putchar('%');
count++;
break;
default:
break;
}
}
else
{
putchar(*format);
count++;
}
format++;
}

va_end(args);

return (count);
}
