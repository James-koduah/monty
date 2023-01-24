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
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * add - add the top two elements
 * @stack: head of list
 * @line_number: line number
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;

	if (h != NULL && h->next != NULL)
	{
		(h->next)->n += h->n;
		pop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

}
/**
 * nop - doesn't do anything
 * @stack: head of list
 * @line_number: line number
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	if (stack && line_number)
	{}
}
/**
 * sub - subtract the top two elements
 * @stack: head of list
 * @line_number: line number
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;
	
	if (h != NULL && h->next != NULL)
	{
		(h->next)->n -= h->n;
		pop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * sub - subtract the top two elements
 * @stack: head of list
 * @line_number: line number
 * Return: void
 */
void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;

	if (h->n == 0)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (h != NULL && h->next != NULL)
	{
		(h->next)->n /= h->n;
		pop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
