#include "monty.h"

/**
 * push - push a new element onto the stack
 * @stack: head of stack;
 * @line_number: line number
 * Return: void
 */
void push(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *new;
	int n;

	if (ele != NULL)
	{
		n = atoi(ele);
		if (n == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	if (ele == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	if (*stack)
		(*stack)->prev = new;
	new->next = *stack;
	new->prev = NULL;
	*stack = new;
}

/**
 * pall - print out all elements of the list
 * @stack: head of stack;
 * @line_number: line number
 * Return: void
 */
void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *h = *stack;


	while (h)
	{
		fprintf(stdout, "%d\n", h->n);
		h = h->next;
	}
}
/**
 * free_list - free the list
 * @head: head of the list
 * Return: void
 */
void free_list(stack_t *head)
{
	stack_t *f;

	while (head)
	{
		f = head;
		head = head->next;
		free(f);
	}
	free(head);
}

/**
 * pint - print out top value of the list
 * @stack: head of stack;
 * @line_number: line number
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
	{
		fprintf(stdout, "%d\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * pop - print out top value of the list
 * @stack: head of stack;
 * @line_number: line number
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *h;

	if (*stack)
	{
		h = *stack;
		*stack = (*stack)->next;
		free(h);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}
