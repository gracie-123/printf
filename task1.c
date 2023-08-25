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
			else if (*ptr == 'd' || *ptr == 'i')
			{
				int num = va_arg(args, int);
				_print_number(num);
				count += _num_length(num);
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

/**
 * _print_number - Prints an integer
 * @num: The integer to print
 */
void _print_number(int num)
{
	if (num < 0)
	{
		num = -num;
		write(1, "-", 1);
	}

	if (num / 10 != 0)
		_print_number(num / 10);

	char digit = (num % 10) + '0';
	write(1, &digit, 1);
}

/**
 * _num_length - Calculates the number of digits in an integer
 * @num: The integer
 * Return: Number of digits
 */
int _num_length(int num)
{
	int length = 0;
	if (num == 0)
		return (1);

	while (num != 0)
	{
		num /= 10;
		length++;
	}
	return (length);
}
