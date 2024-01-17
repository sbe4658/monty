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
	int cnt = 0;
	stack_t *tempo = NULL;

	tempo = *tophead;

	for (; tempo != NULL; tempo = tempo->next, cnt++)
		;

	if (cnt < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", numline);
		free_all();
		exit(EXIT_FAILURE);
	}

	tempo = (*tophead)->next;
	tempo->n += (*tophead)->n;
	_pop(tophead, numline);
}

/**
 * _nop - do anythinhg
 *
 * @tophead: the head of the linked list
 * @numline: numbers line
 * Return: return nothing
 */

void _nop(stack_t **tophead, unsigned int numline)
{
	(void)tophead;
	(void)numline;
}

