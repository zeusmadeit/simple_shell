#include "main.h"

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated with a call to malloc
 * @old_size: size, in bytes, of the allocated space for ptr
 * @new_size: is the new size, in bytes of the new memory block
 *
 * Return: pointer to new memory allocated
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *nptr = NULL;
	char *optr = ptr;
	unsigned int i;

	if (old_size == new_size)
		return (optr);

	if (optr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(optr);
		return (NULL);
	}

	nptr = malloc(new_size);
	if (nptr == NULL)
	{
		free(optr);
		return (NULL);
	}

	for (i = 0; i < old_size && i < new_size; i++)
		nptr[i] = optr[i];

	free(optr);
	return (nptr);
}


