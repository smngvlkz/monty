#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * append_node_end - add a node at the end of the doubly
 * linked list
 * @head: first position of linked list
 * @n: data to store
 * Return: a pointer to the newly added node
 */
stack_t *append_node_end(stack_t **head, int n)
{
	stack_t *temp, *h;

	if (head == NULL)
		return (NULL);

	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}

	temp->n = n;
	temp->next = NULL;

	if (*head == NULL)
	{
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}

	h = *head;
	while (h->next != NULL)
		h = h->next;
	temp->prev = h;
	h->next = temp;
	return (temp);
}

/**
 * append_node - add a node at the beginning of the doubly
 * linked list
 * @head: first position of linked list
 * @n: data to store
 * Return: a pointer to the newly added node
 */
void append_node(stack_t **head, int n)
{
	stack_t *temp;

	if (head == NULL)

		return;

	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return;
	}

	temp->n = n;
	temp->next = *head;
	temp->prev = NULL;

	if (*head != NULL)
		(*head)->prev = temp;

	*head = temp;
}

/**
 * clear_dlist - frees the doubly linked list
 * @head: head of list
 * Return: no return
 */
void clear_dlist(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
