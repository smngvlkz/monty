#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>


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
	unsigned int cont;
	stack_t *head;
	FILE *fd;
	char *buffer;
} global_t;

extern global_t vglo;

/* PROTOTYPES */
void _push(stack_t **stack, unsigned int line_number);
void pall_it(stack_t **stack, unsigned int counter);
void nop_do(stack_t **head, unsigned int counter);
void _pint(stack_t **head, unsigned int line_number);
void _pop(stack_t **head, unsigned int nlines);
void _swap(stack_t **head, unsigned int nlines);
void add_it(stack_t **head, unsigned int counter);
void sub_it(stack_t **head, unsigned int counter);
void stack_set(stack_t **head, unsigned int counter);
void queue_set(stack_t **head, unsigned int counter);
void div_it(stack_t **head, unsigned int nlines);
void mul_it(stack_t **head, unsigned int nlines);
void mod_it(stack_t **head, unsigned int nlines);


/* fetch function */
void (*fetch_opcodes(char *opc))(stack_t **stack, unsigned int line_number);

/* doubly linked list functions */
stack_t *append_node_end(stack_t **stack, int n);
void append_node(stack_t **head, int n);
void clear_dlist(stack_t *head);

/* imported */
char *_strtoki(char *s, char *d);
int search_char(char *s, char c);
int _strcmp(char *s1, char *s2);
void *calloc(unsigned int elem, unsgined int size);
void *realloc(void *ptr, unsigned int osize, unsigned int nsize);

/* main */
void clear_vglo(void);

#endif /* MONTY_H */
