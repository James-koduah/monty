#include "monty.h"

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

void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *h = *stack;


	while (h)
	{
		fprintf(stdout, "%d\n", h->n);
		h = h->next;
	}
}

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
