#include "monty.h"
/**
 * main - main function
 *
 *
 * Return: something
 */
int main(int argc, char *argv[])
{
	char line_buf[1000];
	FILE *file_h;/*file handle*/
	int i = 0, match = 0;
	functions funcs[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	char *token, *token2;
	int *push_stack = malloc(sizeof(int));
	int linecount = 1; 

	*push_stack = -1;
	if (argc != 2)
	{
		free(push_stack);
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* open the file */
	file_h = fopen(argv[1], "r");
	if (!file_h)
	{
		free(push_stack);
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line_buf, 1000, file_h))
	{
		token = strtok(line_buf, " \n");
		if (token == NULL)
		{
			i = 2;
		}
		token2 = strtok(NULL, " \n"); 
		while (funcs[i].op != NULL)
		{
			if (strcmp(token, funcs[i].op) == 0)
			{
				funcs[i].f(token2, linecount, push_stack);
				match = 1;
			}
			i++;
		}
		
		if (match == 0)
		{
			free(push_stack);
			fprintf(stderr, "L%d: unknown instruction %s\n", linecount, token);
			exit(EXIT_FAILURE);
		}

		i = 0;
		match = 0;
		linecount++;
	}
	fclose(file_h);
	free(push_stack);
	return (0);
}
