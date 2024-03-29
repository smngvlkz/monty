#include "monty.h"

/**
 * my_rotl - rotates the first element to the bottom and second to
 * the top
 * @head: head of the linked list
 * @nlines: line number
 * Return: no return
 */
void my_rotl(stack_t **head, unsigned int nlines)
{
	stack_t *h1 = NULL;
	stack_t *h2 = NULL;
	(void)nlines;

	if (*head == NULL)
		return;

	if ((*head)->next == NULL)
		return;

	h1 = (*head)->next;
	h2 = *head;

	for (; h2->next != NULL; h2 = h2->next)
		;

	h1->prev = NULL;
	h2->next = *head;
	(*head)->next = NULL;
	(*head)->prev = h2;
	*head = h1;
}

/**
 * my_rotr - reverse the stack
 *
 * @head: head of the linked list
 * @nlines: line number
 * Return: no return
 */
void my_rotr(stack_t **head, unsigned int nlines)
{
	stack_t *last = *head;
	(void)nlines;
	
	if (*head == NULL || (*head)->next == NULL)
		return;
	
	while (last->next != NULL)
		last = last->next;
	
	last->prev->next = NULL;
        last->next = *head;
        last->prev = NULL;
        (*head)->prev = last;
        *head = last;
}
