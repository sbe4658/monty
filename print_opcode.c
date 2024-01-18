#include "monty.h"
/**
 * pchar - prints a character.
 * @stack: the top.
 * @line_number: line number.
 *
 * Return: Nothing.
 */
void pchar(stack_t **stack, u_int line_number)
{
	stack_t *h = *stack;

	if (h)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n", line_number);
		free_all(stack);
	}
	if (isascii(h->n))
		printf("%c\n", h->n);
	else
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", line_number);
		free_all(stack);
	}
}
/**
 * pstr - prints a string. 
 * @stack: the top.
 * @line_number: line number.
 *
 * Return: Nothing.
 */
void pchar(stack_t **stack, u_int line_number)
{
	stack_t *h= *stack;

	while (h)
	{
		if (!isascii(h->n))
			break;
		putchar(h->n);
	}
	printf("\n");
	}
}
