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
#include <ctype.h>

typedef unsigned int u_int;
/**
 * struct file_line_s - singly linked list stores lines from read file.
 * @content: a string or the line content.
 * @num:: line number.
 * @next: the next node in the list.
 *
 * Description: Singly linked list node structure.
 */
typedef struct file_line_s
{
	char *content;
	u_int num;
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
} instruction_t;

/* Functions */
void process_lines(void);
void (*look_for(char *instruction))(stack_t **stack, u_int line_number);
int check_digits(char *);
int skip_line(char *);

/* File line functions */
fline_t *add_line_end(char *, u_int);
char *opcode_at(u_int idx);
void free_fline(void);

/* Stack functions */
stack_t *add_elem(stack_t **, int);
void free_stack(stack_t **);
int len_stack(stack_t *);
stack_t *add_elem_end(stack_t **, int);

/* Basic opcodes */
void _pall(stack_t **tophead, unsigned int numline);
void _pop(stack_t **tophead, unsigned int numline);
void _pint(stack_t **tophead, unsigned int numline);
void push(stack_t **tophead, unsigned int numline);
void _swap(stack_t **tophead, unsigned int numline);

/* Math opcodes */
void _add(stack_t **tophead, unsigned int numline);
void sub(stack_t **tophead, unsigned int numline);
void _div(stack_t **tophead, unsigned int numline);
void mul(stack_t **tophead, unsigned int numline);
void mod(stack_t **tophead, unsigned int numline);

/* Printing opcode */
void pchar(stack_t **, unsigned int);
void pstr(stack_t **, unsigned int);
void rotr(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);

/* Error functions */
void malloc_fail(void);
void free_all(stack_t **stack);

/* Global variable */
extern fline_t *first_line;

#endif
