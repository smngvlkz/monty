#include "monty.h"
#include <string.h>

/**
 * fetch_opcodes - selects the correct opcode to perform
 *
 * @opc: opcode passed
 *
 * Return: pointer to the function that executes the opcode
 */
void (*fetch_opcodes(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", _push},
		{"pall", pall_it},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", add_it},
		{"nop", nop_do},
		{"stack", stack_set},
		{"queue", queue_set},
		{"sub", sub_it},
		{"div", div_it},
		{"mul", mul_it},
		{"mod", mod_it},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instruct[i].opcode; i++)
	{

		if (strcmp(instruct[i].opcode, opc) == 0)
			return (instruct[i].f);
	}
	return (NULL);
}
