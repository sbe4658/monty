#include "monty.h"
/**
 * check_digits - checks for digits in a string.
 * @s: string.
 *
 * Return: on Success 0, otherwise -1.
 */
int check_digits(char *s)
{
	int i = 0;

	for (; s[i]; i++)
	{
		if (isdigit(s[i]) == 0)
			return (-1);
	}
	return (0);
}
