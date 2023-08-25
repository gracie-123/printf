#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 * @...: Variadic arguments
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *ptr = format;

	va_start(args, format);

	while (*ptr)
	{
		if (*ptr != '%')
		{
			write(1, ptr, 1);
			count++;
		}
		else
		{
			ptr++;
			if (*ptr == 'c')
			{
				int c = va_arg(args, int);

				write(1, &c, 1);
				count++;
			}
			else if (*ptr == 's')
			{
				char *str = va_arg(args, char *);

				if (str)
				{
					while (*str)
					{
						write(1, str, 1);
						str++;
						count++;
					}
				}
			}
			else if (*ptr == '%')
			{
				write(1, "%", 1);
				count++;
			}
		}
		ptr++;
	}

	va_end(args);
	return (count);
}
