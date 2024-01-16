#include "monty.h"

/**
 * _pint - display the top value in the stack
 *
 * @tophead: the head of the linked list
 * @numline: numbers of line 
 * Return: return nothing
 */

void _pint(stack_t **tophead, unsigned int numline)
{
	(void)numline;

	if (*tophead == NULL)
	{
		dprintf(2, "L%u: ", numline);
		dprintf(2, "can't pint, stack empty\n");
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*tophead)->n);
}
