#include "monty.h"

char *ele = "";
/**
 * main - main. function
 * @ac: ac
 * @av: av
 * Return: int
 */
int main(int ac, char *av[])
{
	char line_buf[1000];
	FILE *fh;
	char *token;
	int i, g = 0;
	instruction_t ins[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{NULL, NULL}
	};
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/* Open file */
	fh = fopen(av[1], "r");
	if (!fh)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line_buf, 999, fh))
	{
		g = 0;
		line_number++;
		token = strtok(line_buf, " \n");
		if (token != NULL)
		{
			for (i = 0; ins[i].opcode != NULL; i++)
			{
				if (strcmp(token, ins[i].opcode) == 0)
				{
					ele = strtok(NULL, " \n");
					ins[i].f(&stack, line_number);
					g = 1;
				}
			}
			if (g == 0)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token); 
				exit(EXIT_FAILURE);
			}
		}
	}
	free_list(stack);
	fclose(fh);
	return (0);

}
