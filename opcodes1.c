#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Pointer to the stack's head.
 * @line_number: Line number in the input file.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;
	char *value = strtok(NULL, " \n");

	if (value == NULL || !is_integer(value))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(value);
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall - Prints all the values on the stack.
 * @stack: Pointer to the stack's head.
 * @line_number: Line number in the input file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	(void)line_number;
}

/**
 * pint - Prints the value at the top of the stack.
 * @stack: Pointer to the stack's head.
 * @line_number: Line number in the input file.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Pointer to the stack's head.
 * @line_number: Line number in the input file.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	next = top->next;

	top->prev = next;
	top->next = next->next;

	if (next->next != NULL)
		next->next->prev = top;
	next->prev = NULL;
	next->next = top;

	*stack = next;
}

/**
 * pop - Removes the top element of the stack.
 * @stack: Pointer to the stack's head.
 * @line_number: Line number in the input file.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	*stack = top->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(top);
}

