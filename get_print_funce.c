#include "main.h"

/**
 * get_print_func - finds the format func
 * @s: the format string
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: the number of bytes printed
 */
int get_print_func(char *s, va_list ap, params_and_flags *params)
{
	int (*func)(va_list, params_and_flags *) = get_specifier_func(s);

	if (func)
		return (func(ap, params));
	return (0);
}