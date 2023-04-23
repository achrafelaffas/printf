#include <stdarg.h>
#include <stdio.h>
/**
 * _print_str - prints a string to stdout
 * @str: the string to print
 *
 * Return: the number of characters printed (excluding null byte)
 */
int _print_str(char *str)
{
int i = 0;

if (str == NULL)
{
str = "(null)";
}

while (str[i] != '\0')
{
putchar(str[i]);
i++;
}

return (i);
}

/**
 * _print_int - prints an integer to stdout
 * @n: the integer to print
 *
 * Return: the number of characters printed (excluding null byte)
 */
int _print_int(int n)
{
unsigned int num;
int digits = 0;
int i = 0;
char buffer[10];

if (n < 0)
{
putchar('-');
num = -n;
}
else
{
num = n;
}

do {
buffer[digits] = num % 10 + '0';
digits++;
num /= 10;
} while (num > 0);

for (i = digits - 1; i >= 0; i--)
{
putchar(buffer[i]);
}

return (digits + (n < 0 ? 1 : 0));
}

/**
 * _vprintf - prints formatted output to stdout using a va_list
 * @format: a string containing format specifiers
 * @args: a va_list of arguments to print
 *
 * Return: the number of characters printed (excluding null byte)
 */
int _vprintf(const char *format, va_list args)
{
int chars_printed = 0;
char *str_arg;
char char_arg;
while (*format != '\0')
{
if (*format != '%')
{
putchar(*format);
chars_printed++;
format++;
continue;
}

format++;

switch (*format)
{
case 's':
str_arg = va_arg(args, char *);
chars_printed += _print_str(str_arg);
break;

case 'c':
char_arg = va_arg(args, int);
putchar(char_arg);
chars_printed++;
break;

default:
putchar('%');
putchar(*format);
chars_printed += 2;
break;
}

format++;
}

return (chars_printed);
}


/**
 * _printf - prints formatted output to stdout
 * @format: a string containing format specifiers
 *
 * Return: the number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
va_list args;
int chars_printed = 0;

if (format == NULL)
return (-1);

va_start(args, format);
chars_printed = _vprintf(format, args);
va_end(args);

return (chars_printed);
}
