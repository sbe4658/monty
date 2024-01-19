#include "monty.h"
/**
 * add_elem - adds an element to the top of the stack.
 * @h: the head.
 * @n: integer.
 *
 * Return: the addr.
 */
stack_t *add_elem(stack_t **h, int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		malloc_fail();
		free_stack(h);
	}
	new->n = n;
	new->prev = NULL;
	if (*h)
		(*h)->prev = new;
	new->next = *h;
	*h = new;
	return (new);
}
/**
 * free_stack - frees the stack.
 * @h: the head.
 *
 * Return: nothing.
 */
void free_stack(stack_t **h)
{
	stack_t *curr = *h;

	while (*h)
	{
		curr = *h;
		*h = (*h)->next;
		free(curr);
	}
	h = NULL;
}
/**
 * len_stack - gets the length of the stack.
 * @h: the head node.
 *
 * Return: The number of elements in the stack.
 */
int len_stack(stack_t *h)
{
	int len = 0;

	for (; h; len++)
		h = h->next;
	return (len);
}
/**
 * add_elem_end - adds an elements to the end.
 * @st: stack.
 * @n: element.
 *
 * Return: address of thenew node.
 */
stack_t *add_elem_end(stack_t **st, int n)
{
	stack_t *new, *h = *st;

	new = malloc(sizeof(stack_t));
	if (!new)
		malloc_fail();
	new->next = NULL;
	new->n = n;
	while (h->next)
		h = h->next;
	if (h)
		h->next = new;
	new->prev = h;
	return (new);
}
