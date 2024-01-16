#ifndef MONTY_H
#define MONTY_H

/* Headers & Macros/typedefs */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef unsigned int u_int;
/**
 * struct file_line_s - singly linked list stores lines from read file.
 * @instruct: a string or the line content.
 * @next: the next node in the list.
 *
 * Description: Singly linked list node structure.
 */
typedef struct file_line_s
{
	char *instruct;
	struct file_line_s *next;
} fline_t;
/**
 * struct stack_s - doubly linked list representation of a stack or (queue).
 * @n: integer.
 * @prev: points to the previous element of the stack (or queue).
 * @next: points to the next element of the stack (or queue).
 *
 * Description: doubly linked list node structure
 *		for stack, queue; LIFO, FIFO.
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode.
 * @f: function to handle the opcode.
 *
 * Description: opcode and its function
 *		for stack, queue; LIFO, FIFO.
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t

/* Functions */
fline_t *add_line_end(char *);
void free_fline(void);
void malloc_fail(void);
void _pall(stack_t **tophead, unsigned int numline);
void _pop(stack_t **tophead, unsigned int numline);
void _pint(stack_t **tophead, unsigned int numline);

/* Global variable */
extern fline_t *first_line;
#endif
