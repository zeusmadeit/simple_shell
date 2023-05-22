#include "main.h"

/**
 * non_inter_shell - non interactive simple shell run.
 * @argc: numer of input arguments.
 * @argv: NULL terminated array of input arguments.
 *
 * Return: 0 on success.
 */

int non_inter_shell(int argc, char *argv[])
{
	char *args_temp[2] = {NULL, NULL};
	int acce = 0, error = 0;

	if (argc > 1)
	{
		/*file input*/
		args_temp[0] = argv[1];
		acce = access(argv[1], R_OK);
		if (acce == 0)
			child_exe(args_temp, argv[0], 1);
	}
	else
	{
		/*commands from pipe*/
		error = non_inter_piped(argv[0]);
	}
	return (error);
}

/**
 * non_inter_piped - runs non interactive shell when input is piped.
 * @argv: name of the program.
 *
 * Return: 0 on success.
 */

int non_inter_piped(char *argv)
{
	char **cmnds = NULL, *buffer = NULL, *token = NULL;
	char *heap_token = NULL;
	size_t size = 0;
	pid_t child_pid;
	int status, error = 0, count = 1;

	while ((getline(&buffer, &size, stdin)) != -1)
	{
		token = strtok(buffer, " \n\t\r");
		if (token != NULL)
		{
			if (check_built_ins(buffer, token) == 1)
				continue;
			heap_token = find_inPath(&token);
			cmnds = input_tokens(token, buffer);
			child_pid = fork();
			if (child_pid == 0)
			{
				child_exe(cmnds, argv, count);
			}
			else
			{
				waitpid(child_pid, &status, 0);
				error = WEXITSTATUS(status);
			}
			free_all(buffer, cmnds, heap_token);
			size = 0;
		}
		count++;
	}
	if (size != 0)
		free(buffer);
	return (error);
}

