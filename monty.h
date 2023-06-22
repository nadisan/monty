#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
instruction_t *in;
FILE *pFile;

void pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int l_num);
void _div(stack_t **stack, unsigned int l_num);
void _mul(stack_t **stack, unsigned int l_num);
void _mod(stack_t **stack, unsigned int l_num);
void pchar(stack_t **stack, unsigned int l_num);
void pstr(stack_t **stack, unsigned int l_num);
void fre(stack_t *stack);
int ex_inst(instruction_t *in, char *buf, unsigned int l_num, stack_t **stack);
int rfile(char *argv[], instruction_t *in);

/**
 * nop - Does nothing
 * @stack: stack linked list
 * @number: number to insert on stack
 */
void nop(__attribute__ ((unused))stack_t **stack
		, __attribute__ ((unused))unsigned int number);

#endif
