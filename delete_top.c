#include "monty.h"

/**
 * _pop - deletes the top element in the stack
 *
 * @tophead: the head of the linked list
 * @numline: numbers of line
 * Return: return nothing
 */

void _pop(stack_t **tophead, unsigned int numline)
{
	stack_t *tempo;

	if (tophead == NULL || *tophead == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", numline);
		exit(EXIT_FAILURE);
	}
	else
	{
		tempo = *tophead;
		*tophead = (*tophead)->next;
		free(tempo);
	}
}
