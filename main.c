#include "monty.h"

global_t vglo;

/**
 * main - monty code interpreter
 * @argc: number of arguments
 * @argv: monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	char *opcode;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
i
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		opcode = strtok(line, "\n\t\r ");
		if (opcode == NULL || opcode[0] == '#')
			continue;

		if (strcmp(opcode, "push") == 0)
		{
			char *arg = strtok(NULL, "\n\t\r ");
			if (arg == NULL || _isdigit(arg))
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				free(line);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			_push(&stack, atoi(arg));
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall_it(&stack, line_number);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			free(line);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}

	free(line);
	fclose(file);
	return (0);
}
