#include "monty.h"
/**
 * push - push on stack
 * @element: element to be pushed
 * @linecount: line number
 * @push_stack: number on stack
 * Return: void
 */
void push(char *element, int linecount, int *push_stack)
{
	int b;
	int v = *push_stack;

	if (element)
	{
		b = atoi(element);
	}
	if (element == NULL || !b)
	{
		fprintf(stderr, "L%d: usage: push integer\n", linecount);
		exit(EXIT_FAILURE);
	}
	v++;
	stack[v] = b;
	*push_stack = v;
}

void pall(__attribute__((unused))char *e, __attribute__((unused))int linecount, int *push_stack)
{
	int i;
	int v = *push_stack;

	if (v >= 0)
	{
		for (i = v; i >=0; i--)
		{
			fprintf(stdout,"%d\n", stack[i]);
		}
	}
}
