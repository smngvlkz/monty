#include "monty.h"

/**
 * nop_do - Does nothing
 * @head: Stack head
 * @counter: Line number
 * Return: No return value
 */
void nop_do(stack_t **head, unsigned int counter)
{
	(void)counter;
	(void)head;
}

/**
 * add_it - Adds the top two elements of the stack
 * @head: Stack head
 * @counter: Line number
 * Return: No return value
 */
void add_it(stack_t **head, unsigned int counter)
{
    int sum;
    stack_t *temp;

    if (*head == NULL || (*head)->next == NULL)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", counter);
        return;
    }

    sum = (*head)->n + (*head)->next->n;
    temp = (*head)->next;
    (*head)->next->n = sum;
    (*head)->next = (*head)->next->next;
    free(temp);
}

/**
 * queue_set - sets the format of the data to a queue
 * (FIFO)
 * @head: head stack
 * @counter: Line number
 * Return: No return
 */
void queue_set(stack_t **head, unsigned int counter)
{
	(void)counter;
	(void)head;

	vglo.lifo = 0;
}

/**
 * stack_set - sets the format of the data to a stack
 * (LIFO)
 * @head: head stack
 * @counter: line number
 * Return: no return
 */
void stack_set(stack_t **head, unsigned int counter)
{
	(void)counter;
	(void)head;

	vglo.lifo = 1;
}

/**
 * sub_it - substracts the top element from the
 * second top element
 * @head: head stack
 * @counter: line number
 * Return: no return
 */
void sub_it(stack_t **head, unsigned int counter)
{
	int diff;
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", counter);
		return;
	}

	diff = (*head)->next->n - (*head)->n;
	temp = (*head)->next;
	(*head)->next->n = diff;
	(*head)->next = (*head)->next->next;
	free(temp);
}
