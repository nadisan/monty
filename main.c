#include <stdio.h>
#include <string.h>
#include "monty.h"
#include <stdlib.h>


int main(int argc, char *argv[])
{
	FILE *pFile;
	char buffer[100];
	/*stack_t *stack = NULL;*/
	/*char *opcode = NULL;	*/
	unsigned int line_number = 0;
	char *fun;

	if (argc == 2)
		pFile = fopen(argv[1], "r");
	if (pFile == NULL)
		perror("Error opening file");
	else
	{
		while (!feof(pFile))
		{
			line_number++;
			if (fgets(buffer, 100, pFile) == NULL)
				break;
			fun = strtok(buffer, " \n");
			printf("%s", fun);
			/*if (strcmp(fun, "push") == 0;
				push(&stack, line_number);
			if (strcmp(fun, "pall") == 0;
				pall(&stack);*/
		}
		fclose(pFile);
	}
	return (0);
}