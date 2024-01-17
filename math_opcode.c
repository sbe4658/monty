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
/**
 * sub - subtracts the top two elements of the stack
 *
 * @tophead:the head of the linked list
 * @numline: numbers line;
 * Return: return nothing
 */
void sub(stack_t **tophead, unsigned int numline)
{
	stack_t *tempo = NULL;

	tempo = *tophead;
	if (len_stack(tempo) < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", numline);
		free_all(tophead);
	}

	tempo = (*tophead)->next;
	tempo->n -= (*tophead)->n;
	_pop(tophead, numline);
}
/**
 * div - divides the top two elements of the stack
 *
 * @tophead:the head of the linked list
 * @numline: numbers line;
 * Return: return nothing
 */
void div(stack_t **tophead, unsigned int numline)
{
	stack_t *tempo = NULL;

	tempo = *tophead;
	if (len_stack(tempo) < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", numline);
		free_all(tophead);
	}
	if (tempo->n == 0)
	{
		dprintf(STDERR_FILENO, "L%i: division by zero\n", numline);
		free_all(tophead);
	}
	tempo = (*tophead)->next;
	tempo->n /= (*tophead)->n;
	_pop(tophead, numline);
}
/**
 * mul - multiplies the top two elements of the stack
 *
 * @tophead:the head of the linked list
 * @numline: numbers line;
 * Return: return nothing
 */
void mul(stack_t **tophead, unsigned int numline)
{
	stack_t *tempo = NULL;

	tempo = *tophead;
	if (len_stack(tempo) < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", numline);
		free_all(tophead);
	}

	tempo = (*tophead)->next;
	tempo->n *= (*tophead)->n;
	_pop(tophead, numline);
}
/**
 * mod - computes the modulos the top two elements of the stack
 *
 * @tophead:the head of the linked list
 * @numline: numbers line;
 * Return: return nothing
 */
void mod(stack_t **tophead, unsigned int numline)
{
	stack_t *tempo = NULL;

	tempo = *tophead;
	if (len_stack(tempo) < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", numline);
		free_all(tophead);
	}
	if (tempo->n == 0)
	{
		dprintf(STDERR_FILENO, "L%i: division by zero\n", numline);
		free_all(tophead);
	}
	tempo = (*tophead)->next;
	tempo->n %= (*tophead)->n;
	_pop(tophead, numline);
}
