#include "shell.h"

/**
 * main - func with infinite loop
 * prompt() - display the shell prompt
 * input - read user input
 * Return: loop
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

		execute_proc(args);

		free(input);
		free(args);
	}

	return 0;
}
