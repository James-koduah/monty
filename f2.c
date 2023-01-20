#include "monty.h"
/**
 * swap - swap the top two elements
 * @stack: head of list
 * @line_number: line number
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;
	int c;
	int d;
	
	if (h != NULL && h->next != NULL)
	{
		c = h->n;
		d = (h->next)->n;
		h->n = d;
		(h->next)->n = c;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
}
