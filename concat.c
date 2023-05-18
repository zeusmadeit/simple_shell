#include "main.h"

/**
 * concat - concatenates two strings into a new memory is allocated.
 * @str1: first string to be concatenated in the sequence.
 * @str2: second string to be concatenated in the sequence.
 *
 * Return: pointer to allocated memory, NULL if fails.
 */

char *concat(const char *str1, const char *str2)
{
	unsigned int len_t = 0;
	int i, j;
	char *temp = NULL;

	len_t = _strlen(str1) + _strlen(str1);

	temp = malloc(sizeof(char) * (len_t + 10));
	if (temp == NULL)
	{
		perror("malloc");
		return (NULL);
	}

	i = 0;
	while (str1[i] != '\0')
	{
		temp[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j] != '\0')
		temp[i++] = str2[j++];
	temp[i] = '\0';

	return (temp);
}

