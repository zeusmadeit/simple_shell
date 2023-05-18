#include "main.h"

/**
 * find_inPath - looks in paths for a function to be valid.
 * @token: token to be looked in the PATH directories.
 *
 * Return: if token is found in PATH return a newly allocated
 *         string with PATH_found/token. NULL if not found.
 */

char *find_inPath(char **token)
{
	int file_stat, i;
	struct stat file_info;
	char *full_path = NULL, *temp = NULL;
	char **paths = NULL;

	if (_strchr(*token, '/') != 0)
		return (NULL);
	paths = store_paths();
	if (paths == NULL)
		return (NULL);
	i = 0;
	while (paths[i] != NULL)
	{
		full_path = concat(paths[i], "/");

		temp = full_path;
		full_path = concat(full_path, *token);

		free(temp);
		file_stat = stat(full_path, &file_info);
		if (file_stat == 0)
			break;

		free(full_path);
		i++;
	}
	if (paths[i] == NULL)
	{
		free(paths[0] - 5);
		free(paths);
		return (NULL);
	}
	*token = full_path;
	free(paths[0] - 5);
	free(paths);
	return (full_path);
}

/**
 * store_paths - looks for PATH in env and returns a newly allocated
 *               array of strings with all the directories in PATH.
 * Return: newly allocated array of strings with all the directories in PATH.
 */

char **store_paths(void)
{
	int i = 0;
	char *token = NULL, *path_c = NULL, **paths = NULL;
	size_t path_sz = 0;

	if (environ == NULL || environ[i] == NULL)
		return (NULL);
	while (environ[i++] != NULL)
		if (_strncmp((const char *)environ[i], "PATH=", 5) == 0)
			break;
	if (environ[i] == NULL)
		return (NULL);
	path_c = malloc(_strlen(environ[i]) + 1);
	if (path_c == NULL)
		return (NULL);
	path_c = _strcpy(path_c, environ[i]);
	token = strtok(path_c, "=");
	i = 0;
	token = strtok(NULL, ":\n");
	while (token != NULL)
	{
		paths = _realloc(paths, path_sz, path_sz + sizeof(char *));
		if (paths == NULL)
		{
			free(path_c);
			return (NULL);
		}
		path_sz += sizeof(char *);
		paths[i++] = token;
		token = strtok(NULL, ":\n");
	}
	paths = _realloc(paths, path_sz, path_sz + sizeof(char *));
	if (paths == NULL)
	{
		free(path_c);
		return (NULL);
	}
	path_sz += sizeof(char *);
	paths[i] = NULL;
	return (paths);
}

