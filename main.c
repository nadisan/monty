#include <stdio.h>
#include <string.h>
#include "monty.h"
#include <stdlib.h>
#include <ctype.h>


/**
 * fre - prints all stack elements
 * @stack: stack linked list
 */
void fre(stack_t *stack)
{
	stack_t *temp = NULL;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	stack = NULL;
}


/**
 * ex_inst - prints all stack elements
 * @in: instruction_t
 * @stack: stack linked list
 * @l_num: number to insert on stack
 * @buf: line from file
 *
 */

void ex_inst(instruction_t *in, char *buf, unsigned int l_num, stack_t **stack)
{
	unsigned int i = 0;
	char *fun[2];

	fun[0] = strtok(buf, " \n");
	fun[1] = strtok(NULL, " \n");


	while (in[i].opcode != NULL)
	{
		if (strcmp(in[i].opcode, fun[0]) == 0)
		{

			if (i == 0 && fun[1] == NULL)
			{
				{
					fprintf(stderr, "L%u: usage: push integer\n", l_num);
					free(fun[1]);
					free(fun[0]);
					exit(EXIT_FAILURE);
				}
			}
			in[i].f(stack, l_num);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", l_num, fun[0]);
	fre(*stack);
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
	char buf[100];
	stack_t *stack = NULL;

	/*char *opcode = NULL;	*/
	unsigned int l_num = 1;

	instruction_t in[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"nop", nop},
		{NULL, NULL}
	};
	if (argc != 2)
	{	fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
		pFile = fopen(argv[1], "r");
	if (pFile == NULL)
	{	fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (!feof(pFile))
	{
		while (fgets(buf, 100, pFile))
		{
			ex_inst(in, buf, l_num, &stack);
			l_num++;
		}
	}
	fclose(pFile);
	fre(stack);
	return (0);
}
