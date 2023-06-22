#include "monty.h"

/**
* main - Entry point.
* @argc: The number of command-line arguments (including the program's name).
* @argv: An array of command-line argument strings.
*
* Return: Always 0.
*/
int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	_execute_(file);

	return (0);
}
