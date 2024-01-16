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
	int fd = 0, chrrd = 0;
	FILE *input_file;
	u_int len = 0;
	char *line = NULL;

	if (ac <= 1)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = open(av[1], O_RDONLY);
	input_file = fdopen(fd, 'r');
	if (fd == -1 || !input_file)
	{
		dprintf("Error: can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (chrrd != -1)
	{
		chrrd = getline(&line, &len, input_file);
		add_line_end(line);
	}
	fclose(input_file);

	return (0);
}
