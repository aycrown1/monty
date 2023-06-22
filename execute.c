#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

void _execute_(FILE *file);
void (*get_opcode(char *opcode))(stack_t **stack, unsigned int line_number);
int is_integer(char *str);

/**
* _execute_ - Executes the instructions in the input file.
* @file: Pointer to the input file.
*/
void _execute_(FILE *file)
{
	stack_t *stack = NULL;
	char *line, *opcode = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	void (*func)(stack_t **, unsigned int);

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		opcode = strtok(line, " \n");
		if (opcode == NULL || opcode[0] == '#')
			continue;

		func = get_opcode(opcode);
		if (func == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}

		func(&stack, line_number);
	}

	free(line);
	fclose(file);
	while (stack != NULL)
		pop(&stack, line_number);
}

/**
* get_opcode - Searches for the corresponding opcode and returns its function.
* @opcode: The opcode to search for.
*
* Return: Pointer to the opcode's function, or NULL if not found.
*/
void (*get_opcode(char *opcode))(stack_t **, unsigned int)
{
	int i = 0;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", op_div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
		{NULL, NULL}};

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
			return (instructions[i].f);
		i++;
	}

	return (NULL);
}

/**
* is_integer - Checks if a string represents a valid integer.
* @str: The string to check.
*
* Return: 1 if the string is a valid integer, 0 otherwise.
*/
int is_integer(char *str)
{
	int i = 0;

	if (str == NULL || *str == '\0')
		return (0);

	if (str[i] == '-')
		i++;

	for (; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}

	return (1);
}
