#include <stdio.h>
#include <string.h>
#include "monty.h"
#include <stdlib.h>


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
		printf("%d\n", current->n);
		current = current->next;
	}
}