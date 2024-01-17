#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 *
 * @tophead:the head of the linked list
 * @numline: numbers line;
 * Return: return nothing
 */

void _add(stack_t **tophead, unsigned int numline)
{
	stack_t *tempo = NULL;

	tempo = *tophead;
	if (len_stack(tempo) < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", numline);
		free_all(tophead);
	}

	tempo = (*tophead)->next;
	tempo->n += (*tophead)->n;
	_pop(tophead, numline);
}