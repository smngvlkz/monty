#include "monty.h"
#include <stdio.h>
#include <ctype.h>

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
	    fprintf(stderr, "L%u: usage: push integer\n", line_number);
	    exit(EXIT_FAILURE);
    }

    for (r = 0; vglo.arg[r] != '\0'; r++)
    {
        if (!isdigit(vglo.arg[r]) && vglo.arg[r] != '-')
        {
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
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
 * @stack: stack head
 *
 * Return: no return
 */
void pall_it(stack_t **stack, unsigned int counter)
{
    stack_t *h;

    (void)counter;

    h = *stack;
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
    if (*head == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", nlines);
        clear_vglo();
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*head)->n);
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
        fprintf(stderr, "L%u: can't pop an empty stack\n", nlines);
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
        fprintf(stderr, "L%u: can't swap, stack too short\n", nlines);
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
