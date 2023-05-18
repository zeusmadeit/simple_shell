#include "main.h"

/**
 * child_exe - executes a command in a child process.
 * @cmnds: NULL terminated pointer array to the command and flags if there are
 * @argv: string holding the name of the current executable.
 * @count: a counting of errors so far.
 *
 * Return: void.
 */

void child_exe(char **cmnds, char *argv, int count)
{
	if (execve(cmnds[0], cmnds, environ) == -1)
	{
		write(STDERR_FILENO, argv, _strlen(argv));
		write(STDERR_FILENO, ": ", 2);
		print_number(count);
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, cmnds[0], _strlen(cmnds[0]));
		write(STDERR_FILENO, ": not found\n", 12);
		exit(EXIT_FAILURE);
	}
}

/**
 * input_tokens - finds and allocates tokens in a buffer.
 * @token: first token to be allocated.
 * @buffer: buffer to continue the tokenize.
 * Return: address of allocated pointers, NULL if fails.
 */

char **input_tokens(char *token, char *buffer)
{
	char **cmnds = NULL;
	size_t c_size = 0;
	int i = 0, last = 0;

	cmnds = _realloc(cmnds, c_size, c_size + sizeof(char *));
	if (cmnds == NULL)
	{
		free(cmnds);
		return (NULL);
	}
	c_size += sizeof(char *);
	cmnds[i++] = token;
	last = _strlen(buffer) + 1;
	token = strtok(buffer + last, " \n\t\r");
	while (token != NULL)
	{
		cmnds = _realloc(cmnds, c_size, c_size + sizeof(char *));
		if (cmnds == NULL)
		{
			free(cmnds);
			return (NULL);
		}
		c_size += sizeof(char *);
		cmnds[i] = token;
		token = strtok(NULL, " \n\t\r");
		i++;
	}
	cmnds = _realloc(cmnds, c_size, c_size + sizeof(char *));
	if (cmnds == NULL)
	{	free(cmnds);
		return (NULL);
	}
	c_size += sizeof(char *);
	cmnds[i] = NULL;
	return (cmnds);
}

