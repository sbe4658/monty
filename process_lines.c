#include "monty.h"
/**
 * process_lines - processes lines of a file.
 *
 * Return: Nothing.
 */
void process_lines(void)
{
	stack_t *top = NULL;
	char *tmp, *check;
	fline_t *line = first_line;
	void (*clear_inst)(stack_t **stack, u_int line_number);

	while (line)
	{
		tmp = strdup(line->content);
		check = strtok(tmp, " \t\r\n");
		if (strcmp("nop", check) == 0 || check[0] == '#')
		{
			line = line->next;
			free(tmp);
			continue;
		}
		clear_inst = look_for(check);
		if (!clear_inst)
		{
			dprintf(2, "L%u: unknown instruction %s\n", line->num, check);
			free_fline();
			free_stack(&top);
			free(tmp);
			exit(EXIT_FAILURE);
		}
		free(tmp);
		clear_inst(&top, line->num);
		line = line->next;
	}
	free_stack(&top);
}
/**
 * look_for - looks for a known insruction.
 * @instruction: a given instruction.
 *
 * Return: On success a function pointer, otherwise NULL.
 */
void (*look_for(char *instruction))(stack_t **stack, u_int line_number)
{
	instruction_t opc[] = {
		{"pall", _pall},
		{"pop", _pop},
		{"pint", _pint},
		{"push", push},
		{"swap", _swap},
		{"add", _add},
		{"sub", sub},
		{"mul", mul},
		{"div", _div},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{NULL, NULL}
	};
	int i = 0;

	while (opc[i].opcode)
	{
		if (!strcmp(opc[i].opcode, instruction))
			return (opc[i].f);
		i++;
	}
	return (NULL);
}
