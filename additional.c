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

	if (s[0] == '-')
		i++;
	for (; s[i]; i++)
	{
		if (isdigit(s[i]) == 0)
			return (-1);
	}
	return (0);
}
/**
 * skip_line - handles empty lines, other cases where line is skipped.
 * @src: source.
 *
 * Return: if line should be skipped otherwise 1.
 */
int skip_line(char *src)
{
	int i;

	if (strcmp(src, "\n") == 0)
		return (0);
	for (i = 0; src[i]; i++)
	{
		if (isalpha(src[i]))
			return (1);
	}
	return (0);
}
