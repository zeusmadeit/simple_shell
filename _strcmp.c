#include "main.h"

/**
 * _strcmp - compares two strings
 * @s1: pointer to first string to be compared
 * @s2: pointer to second string to be compared
 *
 * Return: integer difference between the first different char
 */

int _strcmp(const char *s1, const char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s1[i] != '\0' || s2[i] != '\0')
		return (s1[i] - s2[i]);

	return (0);
}

/**
 * _strncmp - compares two strings up to n bytes.
 * @s1: pointer to first string to be compared on its first n bytes.
 * @s2: pointer to second string to be compared on its first n bytes.
 * @n: number of bytes to be compared.
 *
 * Return: difference between the first different char, 0 if equal.
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i = 0;

	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i == n)
		return (0);

	if (s1[i] != '\0' || s2[i] != '\0')
		return (s1[i] - s2[i]);

	return (0);
}

/**
 * _strchr - function that locates a character in a string
 * @s: pointer to string
 * @c: character to be found
 *
 * Return: pointer to the 1st occurrence of c in s. Null if not found.
 */

char *_strchr(char *s, char c)
{
	for (; *s != '\0'; s++)
	{
		if (*s == c)
			return (s);
	}
	if (*s == c)
		return (s);

	return (NULL);
}


