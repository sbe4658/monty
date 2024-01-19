#include "monty.h"

fline_t *first_line = NULL;

/**
 * main - monty Bytecode interpreter.
 * @ac: argument count.
 * @av: argument vector.
 *
 * Return: On success 0, -1 or 1 on failure.
 */
int main(int ac, char **av)
{
	int fd = 0, n = 1;
	FILE *input_file;
	size_t len = 0;
	char *line = NULL;

	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = open(av[1], O_RDONLY);
	input_file = fdopen(fd, "r");
	if (fd == -1 || !input_file)
	{
		dprintf(2, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, input_file) != -1)
	{
		if (skip_line(line))
			add_line_end(line, n);
		n++;

	}
	free(line);
	fclose(input_file);
	process_lines();
	free_fline();
	return (0);
}
