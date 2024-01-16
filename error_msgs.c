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
/**
 * free_all - frees everything and exits with EXIT_FAILURE
 * @stack: stack.
 *
 * Return: Nothing.
 */
void free_all(stack_t **stack)
{
	free_stack(stack);
	free_fline();
	exit(EXIT_FAILURE);
}
