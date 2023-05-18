#include "main.h"

/**
 * welcomeScreen - Method used to print the welcome screen of our shell
 */
void	welcomeScreen()
{
	printf("\n\t============================================\n");
	printf("\t               Simple Shell\n");
	printf("\t--------------------------------------------\n");
	printf("\t             ALX-SE Course Project");
	printf("\n\t============================================\n");
	printf("\n\n");
}

/**
 * changeDirectory - Method to change directory
 */
int changeDirectory(char* arg)
{
	if (arg == NULL) /** If we write no path (only 'cd'), then go to the home directory */
	{
		chdir(getenv("HOME")); 
		return 1;
	}
	else /** Else we change the directory to the one specified by the argument, if possible */
	{
		if (chdir(arg) == -1) 
		{
			printf(" %s: no such directory\n", arg);
            return -1;
		}
	}
	return 0;
}

/**
 * free_all - function that frees allocated memory
 * @buffer: buffer
 * @commands: commands
 * @heap_token: heap_token
*/

void free_all(char *buffer, char **commands, char *heap_token)
{
	if (buffer != NULL)
	{
		free(buffer);
		buffer = NULL;
	}
	if (commands != NULL)
	{
		free(commands);
		commands = NULL;
	}
	if (heap_token != NULL)
	{
		free(heap_token);
		heap_token = NULL;
	}
}

/**
 * print_number - prints an integer
 * @n: input number to be printed
 *
 * Return: void
 */

void print_number(int n)
{
	int res = n, fact = 1;
	char digit = '0';

	while (res / 10)
	{
		fact *= 10;
		res /= 10;
	}
	while (fact)
	{
		res = n / fact;
		digit = res + '0';
		write(STDERR_FILENO, &digit, 1);
		n = n - (res * fact);
		fact /= 10;
	}
}

