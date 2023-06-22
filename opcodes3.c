#include "monty.h"

void nop(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

/**
* nop - Doesn't do anything.
* @stack: Pointer to the stack's head.
* @line_number: Line number in the input file.
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
* pchar - Prints the character at the top of the stack.
* @stack: Pointer to the stack's head.
* @line_number: Line number in the input file.
*/
void pchar(stack_t **stack, unsigned int line_number)
{
    int value = 0;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = (*stack)->n;
	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", value);
}

/**
* pstr - Prints the string starting at the top of the stack.
* @stack: Pointer to the stack's head.
* @line_number: Line number in the input file.
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current != NULL && current->n != 0 && current->n >= 0 && current->n <= 127)
	{
		if (current->n == ' ')
			break;
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}

/**
* rotl - Rotates the stack to the top.
* @stack: Pointer to the stack's head.
* @line_number: Line number in the input file.
*/
void rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack, *top;
    (void)line_number;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        return;
    }
    top = (*stack)->next;
    top->prev = NULL;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = *stack;
    (*stack)->next = NULL;
    (*stack)->prev = current;
    (*stack) = top;
}

/**
* rotr - Rotates the stack to the bottom.
* @stack: Pointer to the stack's head.
* @line_number: Line number in the input file.
*/
void rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *last = NULL;
	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		last = *stack;
		while (last->next != NULL)
			last = last->next;

		last->next = *stack;
		(*stack)->prev = last;
		*stack = last->prev;
		(*stack)->next = NULL;
		last->prev = NULL;
	}
}

