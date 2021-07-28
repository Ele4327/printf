#include "holberton.h"

/**
 * _printf_s - function that prints a string
 * @s: va_list
 * Return: string's length
 */

int _printf_s(va_list s)
{
	int size;
	char *str;

	str = va_arg(s, char *);

	if (str == NULL)
	{
		_printf("(null)");
		return (6);
	}

	size = write(1, str, _strlen(str));

	return (size);
}

/**
 * _printf_c - function that prints a character
 * @c: va_list
 * Return: 1
 */

int _printf_c(va_list c)
{
	int cstr = va_arg(c, int);

	if (c == NULL)
		return (-1);

	write(1, &cstr, 1);

	return (1);
}

/**
 * _printf_d - function that prints a decimal number
 * @d: va_list
 * Return: 1
 */

int _printf_d(va_list d)
{
	int length = 0;
	int num = va_arg(d, int);
	int firsts_num;
	int last_num;
	char buffer[1024];
	char buffer_ln[1];
	if (num < -9 || num > 9)
	{
		firsts_num = num / 10;
		last_num = _abs(num % 10);
		_itoa(firsts_num, buffer, 10);
		_itoa(last_num, buffer_ln, 10);
		length = write(1, buffer, _strlen(buffer));
		length += write(1, buffer_ln, _strlen(buffer_ln));
	}
	else
	{
		_itoa(num, buffer, 10);
		length = write(1, buffer, _strlen(buffer));
	}
	return (length);
}

/**
 * _printf_i - function that prints an integer
 * @i: va_list
 * Return: 1
 */

int _printf_i(va_list i)
{
	int length;
	length = _printf_d(i);
	return (length);
}

/**
 * _printf_per - function that prints a percentage value
 * @p: va_list
 * Return: 1
 */
int _printf_per(va_list p)
{
	_putchar('%');
	(void)p;
	return (1);
}
