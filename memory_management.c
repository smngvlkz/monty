#include "monty.h"

/**
 * calloc - concatanetes two strings
 * @elem: number of elements
 * @size: type of elements
 * Return: no return
 */
void *calloc(unsigned int elem, unsigned int size)
{
	void *c = NULL;
	unsigned int i;

	if (elem == 0 || size == 0)
	{
		return (NULL);
	}
	c = malloc(elem * size);
	if (c == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < (elem * size); i++)
	{
		*((char *)(c) + i) = 0;
	}
	return (c);
}

/**
 * realloc - change the size and copy the content
 * @ptr: malloc pointer to reallocate
 * @osize: old number of bytes
 * @nsize: new number of bytes
 * Return: no return
 */
void *realloc(void *ptr, unsigned int osize, unsigned int nsize)
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
