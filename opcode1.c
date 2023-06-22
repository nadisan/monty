#include <stdio.h>
#include <string.h>
#include "monty.h"
#include <stdlib.h>


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
	fprintf(stdout, "L%u:  can't swap, stack too short", l_num);
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
	fprintf(stdout, "L%u:  can't add, stack too short", l_num);
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
	fprintf(stdout, "L%u:  can't add, stack too short", l_num);
	exit(EXIT_FAILURE);
}
