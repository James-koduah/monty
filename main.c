#include "monty.h"
int stack[LIMIT] = {0};
int push_stack = -1;
 
void exit_str(char *mess)
{
	fprintf(stderr, "%s", mess);
	exit(EXIT_FAILURE);
}

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
	int i = 0;
	functions funcs[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	char *token, *token2;

	if (argc < 2)
		exit_str("USAGE: monty file\n");

	/* open the file */
	file_h = fopen(argv[1], "r");
	if (!file_h)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line_buf, 1000, file_h))
	{
		token = strtok(line_buf, " \n");
		token2 = strtok(NULL, " \n"); 
		while (funcs[i].op != NULL)
		{
			if (strcmp(token, funcs[i].op) == 0)
				funcs[i].f(token2);
			i++;
		}
		i = 0;
	}
	fclose(file_h);
	return (0);
}
