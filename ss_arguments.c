#include "shell.h"

/**
 * main - func with infinite loop
 * args - tokenize the input
 * free(input) - free allocated memory
 * Return: 0 for success
 **/

int main(void)
{
	char *input;
	char **args;

	while (1)
	{
		prompt();
		input = show_input();
		args = identify_string(input);

		if (args[0] != NULL)
		{
			if (compare(args[0], "exit") == 0)
			{
				free(input);
				free(args);
				break;
			}
			
			execute_proc(args);
		}
		free(input);
		free(args);
	}

	return 0;
}
