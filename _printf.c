#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - Prints formatted output to stdout
 * @format: Format string with zero or more directives
 * @...: Optional arguments to substitute in the format string
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					{
						int c = va_arg(args, int);

						putchar(c);
						count++;
					}
				case 's':
					{
						const char *s = va_arg(args, const char *);

						while (*s)
						{
							putchar(*s);
							s++;
							count++;
						}
					}
					break;
				case '%':
					{
						putchar('%');
						count++;
						break;
					}
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
