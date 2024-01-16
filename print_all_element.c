#include "monty.h"

/**
 * _pall - prints all the values on the stack starting from the top
 *
 * @tophead: The head of the linked list
 * @numline: numbers of line
 * Return: Return nothing
 */

void _pall(stack_t **tophead, unsigned int numline)
{
	stack_t *pprin;

	pprin = *stack;
	if (!pprin)
		return;
	while (pprin != NULL)
	{
		printf("%d\n", pprin->n);
		pprin = pprin->next;
	}
}
