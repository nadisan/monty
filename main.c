#include <stdio.h>
#include <string.h>
#include "monty.h"
#include <ctype.h>


/**
 * fre - prints all stack elements
 * @stack: stack linked list
 * @pFile: file
 */
void fre(stack_t *stack, FILE *pFile)
{
	stack_t *temp = NULL;

	fclose(pFile);
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
 * Return: 1 for errors, and 0 for none
 */

int ex_inst(instruction_t *in, char *buf, unsigned int l_num
		, stack_t **stack)
{
	unsigned int i = 0, num;
	char *fun[2];
	char *pEnd;

	fun[0] = strtok(buf, " \n");
	fun[1] = strtok(NULL, " \n");

	if (fun[0] == NULL)
		return (0);
	while (in[i].opcode != NULL)
	{
		if (strcmp(in[i].opcode, fun[0]) == 0)
		{
			if (i == 0)
			{
				if (fun[1] != NULL)
				{
					if (strcmp(fun[1], "0") == 0)
					{	in[i].f(stack, 0);
						return (0);
					}
					num = strtol(fun[1], &pEnd, 10);
					if (num != 0)
					{	in[i].f(stack, num);
						return (0);
					}
				}
				fprintf(stderr, "L%u: usage: push integer\n", l_num);
				return (1);
			}
			in[i].f(stack, l_num);
			return (0);
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", l_num, fun[0]);
	return (1);
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
	unsigned int l_num = 1;

	instruction_t in[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", _div},
		{"mul", _mul},
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
			if (ex_inst(in, buf, l_num, &stack))
			{	fre(stack, pFile);
				exit(EXIT_FAILURE);
			}
			l_num++;
		}
	}
	fre(stack, pFile);
	return (0);
}
