#include "monty.h"


/**
 * mul - subtract the top two elements
 * @stack: head of list
 * @line_number: line number
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;

	if (h != NULL && h->next != NULL)
	{
		(h->next)->n *= h->n;
		pop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
