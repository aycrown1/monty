#include "monty.h"

void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);

/**
 * stack - Sets the format of the data to a stack (LIFO).
 * @stack: Pointer to the stack's head.
 * @line_number: Line number in the input file.
 */
void stack(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
/*
 * This function is not required as
 * the default mode is already stack (LIFO)
 */
}

/**
 * queue - Sets the format of the data to a queue (FIFO).
 * @stack: Pointer to the stack's head.
 * @line_number: Line number in the input file.
 */
void queue(stack_t **stack, unsigned int line_number)
{
stack_t *current = NULL;

(void)line_number;

if (*stack != NULL)
{
current = *stack;
while (current->next != NULL)
current = current->next;

current->next = *stack;
(*stack)->prev = current;
*stack = (*stack)->next;
(*stack)->prev->next = NULL;
(*stack)->prev = NULL;
}
}
