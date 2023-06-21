#include <stdio.h>
#include <string.h>
#include "monty.h"
#include <stdlib.h>

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
	unsigned int i = 0, j = 0;
	char *fun[3];

	fun[j] = strtok(buf, " \n");

	while (fun[j] && j < 2)
	{
		j++;
		fun[j] = strtok(NULL, " \n");
	}

	while (in[i].opcode != NULL)
	{
		if (strcmp(in[i].opcode, fun[0]) == 0)
		{

			if (i == 0 && j != 2)
			{
				{	fprintf(stderr, "L%u: usage: push integer\n", l_num);
					exit(EXIT_FAILURE);
				}
			}
			in[i].f(stack, l_num);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", l_num, fun[1]);
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
	stack_t *temp = NULL;
	/*char *opcode = NULL;	*/
	unsigned int l_num = 0;

	instruction_t in[] = {
		{"push", push},
		{"pall", pall},
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
	else
	{
		while (!feof(pFile))
		{	l_num++;
			if (fgets(buf, 100, pFile) == NULL)
				break;
			ex_inst(in, buf, l_num, &stack);
		}
		fclose(pFile);
	}
	while (stack)
	{	temp = stack;
		stack = stack->next;
		free(temp);
	}
	return (0);
}
