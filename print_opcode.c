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

	if (!h)
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
void pstr(stack_t **stack, __attribute__((unused)) u_int line_number)
{
	stack_t *h = *stack;

	while (h)
	{
		if (!isascii(h->n) || h->n == 0)
			break;
		putchar(h->n);
		h = h->next;
	}
	printf("\n");
}
/**
 * rotl - rotate the stack to the top.
 * @stack: the top.
 * @line_number: line number.
 *
 * Return: Nothing.
 */
void rotl(stack_t **stack, __attribute__((unused)) u_int line_number)
{
	int tmp = 0;
	stack_t *h = *stack;

	if (len_stack(h) == 2)
		_swap(stack, line_number);
	if (len_stack(h) > 3)
	{
		tmp = h->n;
		_pop(stack, line_number);
		add_elem_end(stack, tmp);
	}
}
/**
 * rotr - rotate the stack to the bottom.
 * @stack: the top.
 * @line_number: line number.
 *
 * Return: Nothing.
 */
void rotr(stack_t **stack, __attribute__((unused)) u_int line_number)
{
	int tmp = 0;
	stack_t *h = *stack;

	if (len_stack(h) > 1)
	{
		tmp = h->n;
		while (h->next)
			h = h->next;
		(*stack)->n = h->n;
		h->n = tmp;
	}
}
