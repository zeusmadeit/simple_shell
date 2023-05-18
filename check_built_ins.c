#include "main.h"

/**
 * check_built_ins - checks if token belongs to any built-in function.
 *                   frees any necessary allocated memory before an exit.
 * @buffer: allocated string from which commands are obtaned.
 * @token: token to be check as a built-in.
 *
 * Return: 1 if found a valid built-in. 0 if not found.
 */

int check_built_ins(char *buffer, char *token)
{
	if ((_strcmp("exit", token)) == 0)
	{
		free(buffer);
		exit(0);
	}
	else if ((_strcmp("env", token)) == 0)
	{
		print_env();
		return (1);
	}
	return (0);
}


/**
 * print_env - prints the environment variables.
 *
 * Return: void
 */
void print_env(void)
{
	unsigned int  i, length;

	if (environ == NULL || *environ[0] == '\0')
		return;
	/*print env*/
	i = 0;
	while (environ[i] != NULL)
	{
		/*env len*/
		length = _strlen(environ[i]);
		/*print env*/
		write(STDOUT_FILENO, environ[i], length);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

