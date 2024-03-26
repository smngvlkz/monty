#include "monty.h"

/**
 * _push - pushes an element to the stack
 * @stack: head of linked list
 * @line_number: line number
 *
 * Return: no return
 */
void _push(stack_t **stack, unsigned int line_number)
{
	int i, r;

	if (!vglo.arg)
	{
		dprintf(2, "L%u: ", line_number);
		dprintf(2, "usage: push integer\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	for (r = 0; vglo.arg[r] != '\0'; r++)
	{
		if (!isdigit(vglo.arg[r]) && vglo.arg[r] != '-')
		{
			dprintf(2, "L%u: ", line_number);
			dprintf(2, "usage: push integer\n");
			free_vglo();
			exit(EXIT_FAILURE);
		}
	}

	i = atoi(vglo.arg);

	if (vglo.lifo == 1)
		add_dnodeint(stack, i);
	else
		add_dnodeint_end(stack, i);
}
