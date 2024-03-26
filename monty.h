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


/**
 * struct global_s - global argument variable
 * and LIFO/FIFO flag
 * @arg: argument to opcode
 * @life: flag to indicate data structure is stack
 * or queue
 *
 * Description: gloabl variable for stack, queues
 * LIFO, FIFO
 */
typedef struct global_s
{
	char *arg;
	int lifo;
} global_t;

extern global_t vglo;

/* PROTOTYPES */
void _push(stack_t **stack, unsigned int line_number);
void pall_it(stack_t **stack, unsigned int line_number);
void add_dnodeint(stack_t **stack, int n);
void add_dnodeint_end(stack_t **stack, int n);

#endif /* MONTY_H */
