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
		{	fprintf(stderr, "L%u: division by zero", l_num);
			exit(EXIT_FAILURE);
		}
		second->n = (second->n % current->n);
		free(current);
		current = NULL;
		second->prev = NULL;
		*stack = second;
		return;
	}
	fprintf(stderr, "L%u: can't mod, stack too short", l_num);
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
		fprintf(stdout, "%c\n", ch);
		return;
	}
		fprintf(stderr, "L%u: can't pchar, stack empty", l_num);
		exit(EXIT_FAILURE);
}

