#include "monty.h"

void push(char *element)
{
	int b = atoi(element);
	if (b == 0)
		return;
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
