#include "monty.h"

/**
 * append_node_end - add a node at the end of the doubly
 * linked list
 * @head: first position of linked list
 * @n: ata to store
 * Return: a doubly linked list
 */
stack_t *append_node_end(stack_t **head, const int n)
{
	stack_t *temp, *h;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		clear_vglo();
		exit(EXIT_FAILURE);
	}
	temp->n = n;

	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}
	h = *head;
	while (h->next)
		h = h->next;
	temp->next = h->next;
	temp->prev = h;
	h->next = temp;
	return (h->next);
}

/**
 * append_node - add a node at the beginning of the doubly
 * linked list
 * @head: first position of linked list
 * @n: data to store
 * Return: a doubly linked list
 */
stack_t *append_node(stack_t **head, const int n)
{
	stack_t *temp;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		clear_vglo();
		exit(EXIT_FAILURE);
	}
	temp->n = n;

	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}
	(*head)->prev = temp;
	temp->next = (*head);
	temp->prev = NULL;
	*head = temp;
	return (*head);
}

/**
 * clear_dlist - frees the doubly linked list
 *
 * @head: head of list
 * Return: no return
 */
void clear_dlist(stack_t *head)
{
	stack_t *temp;

	while ((temp = head) != NULL)
	{
		head = head->next;
		free(temp);
	}
}
