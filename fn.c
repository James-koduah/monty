#include "monty.h"

void push(char *element)
{
	int b;
	
	if (element == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", linecount);
		exit(EXIT_FAILURE);
	}
	b = atoi(element);
	push_stack++;
	stack[push_stack] = b;
}

void pall(__attribute__((unused))char *e)
{
	int i;

	if (push_stack > 0)
	{
		for (i = push_stack; i >=0; i--)
		{
			printf("%d\n", stack[i]);
		}
	}
}
