#include "monty.h"
#include <ctype.h>

global_t vglo;

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
			clear_vglo();
			exit(EXIT_FAILURE);
		}
	}

	i = atoi(vglo.arg);

	if (vglo.lifo == 1)
		append_node(stack, i);
	else
		append_node_end(stack, i);
}


/**
 * pall_it - Prints the stack
 *
 * @head: stack head
 * @counter: no used
 *
 * Return: no return
 */
void pall_it(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * _pint - prints the value at the top of the stack
 *
 * @head: head of the linked list
 * @nlines: line number
 * Return: no return
 */
void _pint(stack_t **head, unsigned int nlines)
{
	(void)nlines;

	if (*head == NULL)
	{
		dprintf(2, "L%u: ", nlines);
		dprintf(2, "can't pint, stack empty\n");
		clear_vglo();
		exit(EXIT_FAILURE);
	}

	print("%d\n", (*head)->n);
}

/**
 * _pop - removes the top element of the stack
 *
 * @head: head of the linked list
 * @nlines: line number
 * Return: no return
 */
void _pop(stack_t **head, unsigned int nlines)
{
	stack_t *h;

	if (head == NULL || *head == NULL)
	{
		dprintf(2, "L%u: cn't pop an empy stack\n", nlines);
		clear_vglo();
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = (*head)->next;
	free(h);
}

/**
 * _swap - swaps thw top two elements of the stack
 *
 * @head: head of the linked list
 * @nlines: line number
 * Return: no return
 */
void _swap(stack_t **head, unsigned int nlines)
{
	int n = 0;
	stack_t *h = NULL;

	h = *head;

	for (; h != NULL; h = h->next, n++)
		;

	if (n < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", nlines);
		clear_vglo();
		exit(EXIT_FAILURE);
	}

	h = *head;
	*head = (*head)->next;
	h->next = (*head)->next;
	h->prev = *head;
	(*head)->next = h;
	(*head)->prev = NULL;
}
