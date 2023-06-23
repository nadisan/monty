#include <stdio.h>
#include <string.h>
#include "monty.h"



/**
 * _mod - prints z first stack elements
 * @stack: stack linked list
 * @l_num: number to insert on stack
 *
 */


void _mod(stack_t **stack, unsigned int l_num)
{
	stack_t *current = *stack;
	stack_t *second = NULL;

	if (current != NULL &&  current->next)
	{
		second = current->next;
		if (current->n == 0)
		{	fprintf(stderr, "L%u: division by zero\n", l_num);
			exit(EXIT_FAILURE);
		}
		second->n = (second->n % current->n);
		free(current);
		current = NULL;
		second->prev = NULL;
		*stack = second;
		return;
	}
	fprintf(stderr, "L%u: can't mod, stack too short\n", l_num);
	exit(EXIT_FAILURE);
}

/**
 * pchar - multiply the first two top elemnt and replace them on the stack
 * @stack: stack linked list
 * @l_num: number to insert on stack
 *
 */


void pchar(stack_t **stack, unsigned int l_num)
{
	stack_t *current = *stack;
	char ch;

	if (current != NULL)
	{
		ch = current->n;
		if (ch > 31 && ch < 127)
		{	fprintf(stdout, "%c\n", ch);
			return;
		}
		fprintf(stderr, "L%u: can't pchar, value out of range\n", l_num);
		exit(EXIT_FAILURE);
	}
		fprintf(stderr, "L%u: can't pchar, stack empty\n", l_num);
		exit(EXIT_FAILURE);
}

/**
 * pstr - multiply the first two top elemnt and replace them on the stack
 * @stack: stack linked list
 * @l_num: number to insert on stack
 *
 */


void pstr(stack_t **stack, unsigned int l_num)
{
	stack_t *current = *stack;
	char ch;

	while (current != NULL && l_num !=0)
	{
		ch = current->n;
		if (ch > 31 && ch < 127)
			fprintf(stdout, "%c", ch);
		else 
		{	fprintf(stdout, "\n");
			return;
		}
		current = current->next;
	}
	fprintf(stdout, "\n");
}

/**
 * rotl - shuffle top elemnt to bottom of stack
 * @stack: stack linked list
 * @l_num: number to insert on stack
 *
 */

void rotl(stack_t **stack, __attribute__((unused)) unsigned int l_num)
{
	stack_t *top = *stack;
	stack_t *end = NULL;

	if (top && top->next)
	{
		end = top->next;
		end->prev = NULL;
		*stack = end;
		while (end->next)
		{
			end = end->next;
		}
		end->next = top;
		top->prev = end;
		top->next = NULL;
		return;
	}
	else
		return;
}

/**
 * rotr - shuffle bottom elemnt to top
 * @stack: stack linked list
 * @l_num: number to insert on stack
 *
 */

void rotr(stack_t **stack, __attribute__((unused)) unsigned int l_num)
{
	stack_t *top = *stack;
	stack_t *nend = NULL;
	stack_t *end = NULL;

	if (top && top->next)
	{
		nend = top->next;
		while (nend->next->next)
		{
			nend = nend->next;
		}
		end = nend->next;
		nend->next = NULL;
		top->prev = end;
		end->next = top;
		end->prev = NULL;
		*stack = end;
		return;
	}
}
