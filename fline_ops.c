#include "monty.h"
/**
 * add_line_end - adds a new element.
 * @content: the line content.
 *
 * Return: the address, otherwise NULL.
 */
fline_t *add_line_end(char *content)
{
	fline_t *new, *h = first_line;

	new = malloc(sizeof(fline_t));
	if (!new)
		malloc_fail();
	new->instruct = content;
	new->next = NULL;
	if (h)
	{
		while (h->next)
			h = h->next;
		h->next = new;
	}
	else
		first_line = new;
	return (new);
}
/**
 * free_fline - frees the list.
 *
 * Return: Nothing.
 */
void free_fline(void)
{
	fline_t *curr;

	while (first_line)
	{
		curr = first_line;
		first_line = first_line->next;
		free(curr);
	}
	first_line = NULL;
}
