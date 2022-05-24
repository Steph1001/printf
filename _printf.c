#include "main.h"

/**
 * _printf - prints anything
 * @format: the format string
 *
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list argparam;
	char *p, *start;
	params_and_flags params = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	va_start(argparam, format);

	if ((format[0] == '%' && !format[1]) || !format)
		return (-1);
	if (format[1] == ' ' && format[0] == '%' && !format[2])
		return (-1);
	for (p =(char *) format; *p; p++)
	{
		init_params(&params, argparam);
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &params)) /* while char at p is flag char */
		{
			p++; /* next char */
		}
		p = get_width(p, &params, argparam);
		p = get_precision(p, &params, argparam);
		if (get_modifier(p, &params))
			p++;
		if (!get_specifier_func(p))
			sum += print_from_to(start, p,
				params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			sum += get_print_func(p, argparam, &params);
	}
	_putchar(-1);
	va_end(argparam);
	return (sum);
}
