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
	int value = line_number;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
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
	unsigned int i = 0;

	while (current != NULL && i <= line_number)
	{
		printf("%d\n", current->n);
		current = current->next;
		i++;
	}
}


instruction_t instructions[] = {
    {"push", push},
    {"pall", pall},
    {NULL, NULL}
};

void execute_instructions(instruction_t *instructions, char *instruction_name, stack_t **stack, unsigned int line_number) {
    int i = 0;
    while (instructions[i].opcode != NULL) {
        if (strcmp(instructions[i].opcode, instruction_name) == 0) {
            instructions[i].f(stack, line_number);
            return;
        }
        i++;
    }
    fprintf(stderr, "L%u: unknown instruction %s\n", line_number, instruction_name);
    exit(EXIT_FAILURE);
}

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
	char *fun;


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
			fun = strtok(buffer, " \n");
			execute_instructions(instructions, fun, &stack, line_number);
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
