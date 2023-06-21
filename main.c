#include <stdio.h>
#include <string.h>
#include "monty.h"
#include <stdlib.h>


/**
 * push - add int to stack as header
 * @stack: stack linked list
 * @line_number: number to insert on stack
 *
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));


	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = line_number;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - prints all stack elements
 * @stack: stack linked list
 * @line_number: number to insert on stack
 *
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;


	while (current != NULL && line_number != 0)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

void exec_inst(instruction_t *instructions, char *buffer, unsigned int line_number, stack_t **stack)
{
	int i = 0, j = 0;
	char *fun[3];

	fun[j] = strtok(buffer, " \n");
	
	while (fun[j] && j < 2)
	{	
		j++;
		fun[j] = strtok(NULL, " \n");
	}
	
	while (instructions[i].opcode != NULL)
	{
		if (strcmp(instructions[i].opcode, fun[0]) == 0)
		{

			if (i == 0 && j != 2)
			{
				{	fprintf(stderr, "L%u: usage: push integer\n", line_number);
                                	exit(EXIT_FAILURE);
				}
			}
			instructions[i].f(stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, fun[1]);
	exit(EXIT_FAILURE);
}
instruction_t instructions[] = {
    {"push", push},
    {"pall", pall},
    {NULL, NULL}
};
/**
 * main- executes command from argument
 * @argc: number of command
 * @argv: operation and command file
 * Return: 0 on success
 *
 */

int main(int argc, char *argv[])
{
	FILE *pFile;
	char buffer[100];
	stack_t *stack = NULL;
	stack_t *temp = NULL;
	/*char *opcode = NULL;	*/
	unsigned int line_number = 0;


	if (argc != 2)
	{	fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
		pFile = fopen(argv[1], "r");
	if (pFile == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	else
	{
		while (!feof(pFile))
		{
			line_number++;
			if (fgets(buffer, 100, pFile) == NULL)
				break;

			exec_inst(instructions, buffer, line_number, &stack);
			/*if (strcmp(fun, "push") == 0)
			*	push(&stack, line_number);
			*else if (strcmp(fun, "pall") == 0)
			*	pall(&stack, line_number);
			* else
			* {
			*	fprintf(stderr, "L%d: unknown instruction %s,\n", line_number, fun);
			*	exit(EXIT_FAILURE);
			*}
			*/
		}
		fclose(pFile);
	}
	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	return (0);
}
