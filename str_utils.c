#include "main.h"

/**
* _putchar - prints character to stdout
* @c: char
* Return: length of characters printed
*/
int	_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

/**
* _print_str - prints @str to stdout
* @str: string
* Return: length of @str printed
*/
int	_print_str(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

/**
 * _strcpy - copies the string pointed to by src into dest
 * @dest: destination of the copy
 * @src: source of the copy
 *
 * Return: char pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		++i;
	}
	*(dest + i) = *(src + i);

	return (dest);
}

/**
 * _strlen - obtains the length of a string
 * @s: char pointer to the first position in string
 *
 * Return: the length of the string as an int
 */

unsigned int _strlen(const char *s)
{
	int count = 0;

	while (s != NULL && *s != '\0')
	{
		s++;
		++count;
	}
	return (count);
}

