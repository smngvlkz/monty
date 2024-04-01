#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * clear_vglo - frees global variables
 * @vglo: global variable struct
 * return: no return
 */
void clear_vglo(global_t *vglo)
{
	clear_dlist(vglo->head);
	free(vglo->buffer);
	fclose(vglo->fd);
}

/**
 * initialize_vglo - initializes global variables
 * @vglo: global variable struct
 * @fd: file descriptor
 * Return: no return
 */
void initialize_vglo(global_t *vglo, FILE *fd)
{
	vglo->lifo = 1;
	vglo->cont = 1;
	vglo->arg = NULL;
	vglo->head = NULL;
	vglo->fd = fd;
	vglo->buffer = NULL;
}

/**
 * validate_input - checks if the file exists and file can be opened
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
 */
FILE *validate_input(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * main - monty code interpreter
 * @argc: number of arguments
 * @argv: monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t size = 256;
	char *lines[2] = {NULL, NULL};

	fd = validate_input(argc, argv);
	initialize_vglo(fd);

	while (fgets(vglo.buffer, size, fd) != NULL)
	{
		char *token = strtok(vglo.buffer, " \t\n");

		lines[0] = token;
		if (lines[0] && lines[0][0] != '#')
		{
			f = fetch_opcodes(lines[0]);
			if (!f)
			{
				fprintf(stderr, "L%u: Unknown instruction: %s\n", vglo.cont, lines[0]);
				clear_vglo();
				exit(EXIT_FAILURE);
			}
			vglo.arg = strtok(NULL, " \t\n");
			f(&vglo.head, vglo.cont);
		}
		vglo.cont++;
	}

	clear_vglo();
	return (0);
}
