#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pchar - Prints the char at the top of the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Line number in the Monty byte code file
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (!top)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (top->n < 0 || top->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	putchar(top->n);
	putchar('\n');
}

/**
 * pstr - Prints the string starting at the top of the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Line number in the Monty byte code file
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;
	while (current != NULL && current->n != 0
&& current->n >= 0 && current->n <= 127)
	{
		putchar(current->n);
		current = current->next;
	}
	putchar('\n');
}
