#include "monty.h"
#include <stdio.h>

/**
 * div_it - divides the second elemt by the top element
 * @head: head stack
 * @nlines: line number
 * Return: no return
 */
void div_it(stack_t **head, unsigned int nlines)
{
	int j = 0;
	stack_t *h = NULL;

	h = *head;

	for (; h != NULL; h = h->next, j++)
		;

	if (j < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", nlines);
		clear_vglo();
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", nlines);
		clear_vglo();
		exit(EXIT_FAILURE);
	}

	h = (*head)->next;
	h->n /= (*head)->n;
	_pop(head, nlines);
}
