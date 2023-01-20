#include "monty.h"

char *ele = "";
int main(int ac, char *av[])
{
	char line_buf[1000];
	FILE *fh;
	char *token;
	int i;
	instruction_t ins[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	stack_t *stack = NULL;
	unsigned int line_number = 1;

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
		token = strtok(line_buf, " \n");
		if (token != NULL)
		{	
			for (i = 0; ins[i].opcode != NULL; i++)
			{
				if (strcmp(token, ins[i].opcode) == 0)
				{
					ele = strtok(NULL, " \n");
					ins[i].f(&stack, line_number);
					line_number++;
				}
			}
		}
	}
	free_list(stack);
	fclose(fh);
	printf("file closed\n");
	return (0);

}
