#include <stdio.h>
#include <string.h>
#include "monty.h"
#include <stdlib.h>


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
	/*stack_t *stack = NULL;*/
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
			printf("%s", fun);
		}
		fclose(pFile);
	}
	return (0);
}
