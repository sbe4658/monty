#include "monty.h"

/**
 * _pall - prints all the values on the stack starting from the top
 *
 * @stack: The head of the linked list
 * @line_number: numbers of line
 * Return: Return nothing
 */

void _pall(stack_t **stack, __attribute__((unused)) u_int line_number)
{
	stack_t *pprin;

	pprin = *stack;
	while (pprin != NULL)
	{
		printf("%d\n", pprin->n);
		pprin = pprin->next;
	}
}
/**
 * _pint - display the top value in the stack
 *
 * @tophead: the head of the linked list
 * @numline: numbers of line
 * Return: return nothing
 */

void _pint(stack_t **tophead, unsigned int numline)
{
	if (*tophead == NULL)
	{
		dprintf(2, "L%u: ", numline);
		dprintf(2, "can't pint, stack empty\n");
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*tophead)->n);
}
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
/**
 * push - pushs a new  element to the stack.
 * @stack: the stack.
 * @line_number: line number.
 *
 * Return: Nothing.
 */
void push(stack_t **stack, u_int line_number)
{
	int n = 0;
	char *tmp, *elem;

	tmp = opcode_at(line_number - 1);
	strtok(tmp, " \t\r");
	elem = strtok(NULL, " \n\t\r");
	if (check_digits(elem))
	{
		dprintf(2, "L%u: usage: push integer\n", line_number);
		free(tmp);
		free_all(stack);
	}
	n = atoi(elem);
	add_elem(stack, n);
	free(tmp);
}
