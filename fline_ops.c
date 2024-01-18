#include "monty.h"
/**
 * add_line_end - adds a new element.
 * @content: the line content.
 * @line_number: line number.
 *
 * Return: the address, otherwise NULL.
 */
fline_t *add_line_end(char *content, u_int line_number)
{
	fline_t *new, *h = first_line;

	new = malloc(sizeof(fline_t));
	if (!new)
		malloc_fail();
	new->content = strdup(content);
	new->num = line_number;
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
		free(curr->content);
		free(curr);
	}
	first_line = NULL;
}
/**
 * opcode_at - gets the specific line content; mainly for push.
 * @idx: index to a line number.
 *
 * Return: The content, or NULL.
 */
char *opcode_at(u_int idx)
{
	fline_t *h = first_line;

	while (h)
	{
		if (h->num == idx)
			return (h->content);
		h = h->next;
	}
	return (NULL);
}
