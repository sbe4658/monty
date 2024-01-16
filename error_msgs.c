#include "monty.h"
/**
 * malloc_fail - prints an err msg.
 *
 * Return: Nothing.
 */
void malloc_fail(void)
{
	dprintf(2, "Error: malloc failed\n");
	free_fline();
	exit(EXIT_FAILURE);
}
