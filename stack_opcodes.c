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
void add_it(stack_t *head, unsigned int counter)
{
    int sum = head->n + head->next->n;
    stack_t *temp = head->next;

    if (head == NULL || head->next == NULL)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", counter);
        return;
    }

    head->next->n = sum;
    head->next = head->next->next;
    free(temp);
}
