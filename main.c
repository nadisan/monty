#include <stdio.h>
#include <string.h>
#include "monty.h"


/**
 * main- executes command from argument
 * @argc: number of command
 * @argv: operation and command file
 * Return: 0 if sucess
 */

int main(int argc, char *argv[])
{
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
		{"mod", _mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"nop", nop},
		{NULL, NULL}
	};
	if (argc != 2)
	{	fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	rfile(argv, in);
	return (0);
}
