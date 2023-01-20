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
	}
	new = malloc(sizeof(stack_t));
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
