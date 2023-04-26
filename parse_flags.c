#include "main.h"
char *parse_flags(const char* format)
{
	char* flags = "";
	if (format[2] == '+')
	{
		flags = "+";
		format++;
	}
	else if (format[2] == ' ')
	{
		flags = " ";
		format++;
	}
	else if (format[2] == '#')
	{
		flags = "#";
		format++;
	}
	return flags;
}
