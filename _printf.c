#include "main.h"
/**
 * check_specifier - check that char is
 * a valid specifier and
 * assigns an appropriate fucntion for
 * its printing.
 * @format: the specifier (char*)
 *
 * Return: pointer to funct if success
 * NULL pointer if not successful
 */
int (*check_specifier(const char *format))(va_list)
{
	int i;

	func_t my_array[6] = {
		{"c", print_char},
		{"s", print_str},
		{"%", print_cent},
		{"i", print_int},
		{"d", print_dec},
		{NULL, NULL}
	};

	for (i = 0; my_array[i].t != NULL; i++)
	{
		if (*(my_array[i].t) == *format)
		{
			return (my_array[i].f);
		}
	}

	return (NULL);
}

/**
 * print_cent - prints character % to
 * stdout
 * @args: variadic parameter
 *
 * Return: number of characters printed
 */
int print_cent(va_list args)
{
	(void)args;

	write(1, "%", 1);

	return (1);
}

/**
 * print_int - prints a given integer
 * from variadic parameters
 * @args: variadic parameter
 *
 * Return: number of characters
 * printed on Success
 */
int print_int(va_list args)
{
	int i = 0;
	int count = 0;
	int numb;
	int my_arr[10];
	char x[1];

/*
 * Fetch integer from variadic *
 * parameters
 */
	numb = va_arg(args, int);

/*
 * Break the numbers apart and
 * assign them to array
 */
	while (numb != 0)
	{
		my_arr[i] = (numb % 10);
		numb = numb / 10;
		if (numb != 0)
			i++;
	}

/*
 * Write the contents of the *
 * array to stdout
 */
	for (i = 0; i >= 0; i--)
	{
/*convert int to char*/
		x[0] = ('0' + my_arr[i]);
		count += write(1, x, 1);
	}

	return (count);
}

/**
 * print_dec - prints a given integer
 * from variadic parameters to base 10
 * @args: variadic parameter
 *
 * Return: number of characters printed
 * on Success
 */
int print_dec(va_list args)
{
	int i = 0;
	int count = 0;
	int numb;
	int my_arr[10];
	char x[1];

/*
 * Fetch integer from variadic *
 * parameters
 */
	numb = va_arg(args, int);

/*
 * Break the numbers apart and *
 * assign them to array
 */
	while (numb != 0)
	{
		my_arr[i] =
(numb % 10);
		numb = numb / 10;
		if (numb != 0)
			i++;
	}

/*
 * Write the contents of the *
 * array to stdout
 */
	for (i = 0; i >= 0; i--)
	{
/*Convert int to char*/
		x[0] = ('0' + my_arr[i]);
		count += write(1, x, 1);
	}

	return (count);
}

/**
 * _printf - prints a str in a format
 * @format: string to print (char *)
 * @...: variadic parameters (unknown)
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
int i = 0;
int count = 0;
int value = 0;
va_list args;

va_start(args, format);
/*Prevent parsing a null pointer*/
if (format == NULL)
	return (-1);
/*Print each character of string*/
while (format[i])
{
	if (format[i] != '%')
	{
	value = write(1, &format[i], 1);
	count = count + value;
	i++;
	continue;
	}
	if (format[i] == '%')
	{
		f = check_specifier(&format[i + 1]);

		if (f != NULL)
		{
		value = f(args);
		count = count + value;
		i = i + 2;
		continue;
		}
		if (format[i + 1] != '\0')
		{
		value = write(1, &format[i + 1], 1);
		count = count + value;
		i = i + 2;
		continue;
		}
	}
}
	return (count);
}
