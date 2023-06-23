#include <stdio.h>
#include <string.h>
#include "monty.h"



/**
 * push - add int to stack as header
 * @stack: stack linked list
 * @l_num: number to insert on stack
 *
 */

void push(stack_t **stack, unsigned int l_num)
{
	stack_t *new_node = malloc(sizeof(stack_t));


	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fre(*stack);
		exit(EXIT_FAILURE);
	}
	new_node->n = l_num;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - prints all stack elements
 * @stack: stack linked list
 * @l_num: number to insert on stack
 *
 */

void pall(stack_t **stack, unsigned int l_num)
{
	stack_t *current = *stack;


	while (current != NULL && l_num != 0)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - prints z first stack elements
 * @stack: stack linked list
 * @l_num: number to insert on stack
 *
 */

void pint(stack_t **stack, unsigned int l_num)
{
	stack_t *current = *stack;

	if (current != NULL && l_num != 0)
	{
		fprintf(stdout, "%d\n", current->n);
		return;
	}
	fprintf(stderr, "L%u: can't pint, stack empty ", l_num);

	fre(*stack);
	exit(EXIT_FAILURE);

}

/**
 * pop - prints z first stack elements
 * @stack: stack linked list
 * @l_num: number to insert on stack
 *
 */

void pop(stack_t **stack, unsigned int l_num)
{
	stack_t *current = *stack;
	stack_t *second;

	if (current != NULL && l_num != 0)
	{
		second = current->next;
		if (second)
			second->prev = NULL;
		*stack = second;
		free(current);
		return;
	}
	fre(*stack);
	fprintf(stderr, "L%u: can't pop, stack empty", l_num);
	exit(EXIT_FAILURE);
}

/**
 * nop - Does nothing
 * @stack: stack linked list
 * @number: number to insert on stack
 */
void nop(__attribute__ ((unused)) stack_t **stack
		, __attribute__ ((unused)) unsigned int number)
{
}
