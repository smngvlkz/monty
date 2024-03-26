#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <stdlib.h>

/**
 * struct stact_s - doubly linked list of a stack/queue
 * @n: integer
 * @prev: points to the previous stack/queue element
 *
 * Description: doubly linked list node structure for
 * stack,queue, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: te opcode
 * @f: function to handle opcode
 *
 * Description: opcode and its function for stack,
 * queues, LIFE, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

#endif /* MONTY_H */
