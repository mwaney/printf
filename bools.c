#include "main.h"

/**
 * bool_print - function evaluates whether a character is
 * printable or not
 *
 * @c: Character.
 * Return: 1 otherwise 0
 */

int bool_print(char c)
{
	if (c >= 32 && c < 127)
	{
		return (1);
	}

	return (0);
}

/**
 * bool_digit - Checks if a character is a digit (0-9).
 *
 * @c:character to check.
 * Return: 1 if the character is a digit, otherwise 0
 */
int bool_digit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);

	return (0);
}
