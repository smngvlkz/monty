#include "monty.h"

/**
 * my_calloc - concatanetes two strings
 * @nmeb: number of elements
 * @size: type of elements
 * Return: no return
 */
void *my_calloc(unsigned int nmeb, unsigned int size)
{
	void *c = NULL;
	unsigned int i;

	if (nmeb == 0 || size == 0)
	{
		return (NULL);
	}
	c = malloc(nmeb * size);
	if (c == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < (nmeb * size); i++)
	{
		*((char *)(c) + i) = 0;
	}
	return (c);
}

/**
 * my_realloc - change the size and copy the content
 * @ptr: malloc pointer to reallocate
 * @osize: old number of bytes
 * @nsize: new number of bytes
 * Return: no return
 */
void *my_realloc(void *ptr, unsigned int osize, unsigned int nsize)
{
	char *c = NULL;
	unsigned int i;

	if (nsize == osize)
		return (ptr);
	if (ptr == NULL)
	{
		c = malloc(nsize);
		if (!c)
			return (NULL);
		return (c);
	}
	if (nsize == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (nsize > osize)
	{
		c = malloc(nsize);
		if (!c)
			return (NULL);
		for (i = 0; i < osize; i++)
			c[i] = *((char *)ptr + i);
		free(ptr);
	}
	else
	{
		c = malloc(nsize);
		if (!c)
			return (NULL);
		for (i = 0; i < nsize; i++)
			c[i] = *((char *)ptr + i);
		free(ptr);
	}
	return (c);
}
