#include "monty.h"
#include <string.h>
#include <stdio.h>
#include <stdio.h>

global_t vglo;

/**
 * clear_vglo - frees global variables
 *
 * return: no return
 */
void clear_vglo(void)
{
	clear_dlist(vglo.head);
	free(vglo.buffer);
	fclose(vglo.fd);
}

/**
 * initialize_vglo - initializes global variables
 *
 * @fd: file descriptor
 * Return: no return
 */
void initialize_vglo(FILE *fd)
{
	vglo.life = 1;
	vglo.cont = 1;
	vglo.arg = NULL;
	vglo.head = NULL;
	vglo.fd = fd;
	vglo.buffer = NULL;
}

/**
 * validate_input - checks if the file exists and file
 * can be opened
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
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * main - monty code interpreter
 *
 * @argc: number of arguments
 * @argv: monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stact_t **stack, unsigned int line_number);
	FILE *fd;
	size_t size = 256;
	ssize_t line_n = 0;
	char *lines[2] = {NULL, NULL};

	fd = validate_input(argc, argv);
	initialize_vglo(fd);
	line_n = getlines(&vglo.bugger, &size, fd);
	while (line_n != -1)
	{
		lines[0] = strtok(vglo.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = fetch_opcodes(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", vglo.cont);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				clear_vglo();
				exit(EXIT_FAILURE);
			}
			vglo.arg = strtok(NULL, " \t\n");
			f(&vglo.head, vglo.count);
		}
		line_n = getline(&vglo.buffer, &size, fd);
		vglo.count++;
	}

	clear_vglo();

	return (0);
}
