#include "shell.h"

/**
 * history - fill file by user input
 * @input: user input
 * Return: -1 Fail 0 Succes
 */

int history(char *input)
{
	char *filename = ".simple_shell_history";
	ssize_t fd, w;
	int length = 0;

	if (!filename)
		return (-1);
	fd = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (fd < 0)
		return (-1);
	if (input)
	{
		while (input[length])
			length++;
		w = write(fd, input, length);
		if (w < 0)
			return (-1);
	}
	return (1);
}

/**
 * free_env - free enviroment variable array
 * @env: environment variables.
 * Return: void
 */

void free_env(char **env)
{
	int x;

	for (x = 0; env[x]; x++)
	{
		free(env[x]);
	}
}
