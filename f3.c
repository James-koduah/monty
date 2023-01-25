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


/**
 * mod - subtract the top two elements
 * @stack: head of list
 * @line_number: line number
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;

	if (h != NULL && h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (h != NULL && h->next != NULL)
	{
		(h->next)->n %= h->n;
		pop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * pchar - subtract the top two elements
 * @stack: head of list
 * @line_number: line number
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int i = (*stack)->n;

	if (i >= 0 && i < 128)
	{
		putchar(i);
		putchar('\n');
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr - subtract the top two elements
 * @stack: head of list
 * @line_number: line number
 * Return: void
 */
void pstr(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *h = *stack;
	int n;

	while (1)
	{
		if (h)
			n = h->n;
		else
			break;
		if (n == 0)
			break;
		putchar(n);
		h = h->next;
	}
	putchar('\n');
}
