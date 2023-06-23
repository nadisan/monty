#include <stdio.h>
#include <string.h>
#include "monty.h"


/**
 * swap - prints z first stack elements
 * @stack: stack linked list
 * @l_num: number to insert on stack
 *
 */


void swap(stack_t **stack, unsigned int l_num)
{
	stack_t *temp = *stack;
	stack_t *first = *stack;
	stack_t *second = NULL;

	if (first != NULL &&  first->next)
	{	second = first->next;
		temp = second->next;
		if (temp)
			temp->prev = first;
		first->next = temp;
		first->prev = second;
		second->next = first;
		second->prev = NULL;
		*stack = second;
		return;
	}
	fprintf(stderr, "L%u: can't swap, stack too short\n", l_num);
	exit(EXIT_FAILURE);
}

/**
 * add - prints z first stack elements
 * @stack: stack linked list
 * @l_num: number to insert on stack
 *
 */


void add(stack_t **stack, unsigned int l_num)
{
	stack_t *current = *stack;
	stack_t *second = NULL;

	if (current != NULL && l_num != 0 &&  current->next)
	{
		second = current->next;
		second->n = (second->n + current->n);
		free(current);
		current = NULL;
		second->prev = NULL;
		*stack = second;
		return;
	}
	fprintf(stderr, "L%u: can't add, stack too short\n", l_num);
	exit(EXIT_FAILURE);
}


/**
 * sub - prints z first stack elements
 * @stack: stack linked list
 * @l_num: number to insert on stack
 *
 */


void sub(stack_t **stack, unsigned int l_num)
{
	stack_t *current = *stack;
	stack_t *second = NULL;

	if (current != NULL && l_num != 0 &&  current->next)
	{
		second = current->next;
		second->n = (second->n - current->n);
		free(current);
		current = NULL;
		second->prev = NULL;
		*stack = second;
		return;
	}
	fprintf(stderr, "L%u: can't sub, stack too short\n", l_num);
	exit(EXIT_FAILURE);
}

/**
 * _div - prints z first stack elements
 * @stack: stack linked list
 * @l_num: number to insert on stack
 *
 */


void _div(stack_t **stack, unsigned int l_num)
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
		second->n = (second->n / current->n);
		free(current);
		current = NULL;
		second->prev = NULL;
		*stack = second;
		return;
	}
	fprintf(stderr, "L%u: can't div, stack too short\n", l_num);
	exit(EXIT_FAILURE);
}

/**
 * _mul - multiply the first two top elemnt and replace them on the stack
 * @stack: stack linked list
 * @l_num: number to insert on stack
 *
 */


void _mul(stack_t **stack, unsigned int l_num)
{
	stack_t *current = *stack;
	stack_t *second = NULL;

	if (current != NULL &&  current->next)
	{
		second = current->next;
		second->n = (second->n * current->n);
		free(current);
		current = NULL;
		second->prev = NULL;
		*stack = second;
		return;
	}
	fprintf(stderr, "L%u: can't div, stack too short\n", l_num);
	exit(EXIT_FAILURE);
}

