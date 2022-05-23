#include "main.h"

/**
 * get_width - gets the width from the format string
 * @s: the format string
 * @param: the parameters struct
 * @argparam: the argument pointer
 *
 * Return: new pointer
 */
char *get_width(char *s, params_and_flags *param, va_list argparam)
/* should this function use char **s and modify the pointer? */
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(argparam, int);
		s++;
	}
	else
	{
		while (_isnum(*s))
			d = d * 10 + (*s++ - '0');
	}
	param->width = d;
	return (s);
}