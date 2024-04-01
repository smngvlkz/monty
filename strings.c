#include "monty.h"

/**
 * _strcmp - function to compare two strings
 * @s1: type string compared
 * @s2: type string compared
 * Return: 0 if s1 and s2 are equals
 * another value if different
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;
	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}

/**
 * search_char - function to find a character in a string
 * @s: string to review
 * @c: char to find
 * Return: 1 if success 0 if not
 */
int search_char(char *s, char c)
{
	int cont = 0;

	while (s[cont] != '\0')
	{
		if (s[cont] == c)
		{
			break;
		}
		cont++;
	}
	if (s[cont] == c)
		return (1);
	else
		return (0);
}

/**
 * _strtoki - function that cut a string into tokens
 * @s: string to tokenize
 * @d: delimiters
 * Return: first partition
 */
char *_strtoki(char *s, char *d)
{
	static char *ultimo;
	int i = 0, r = 0;

	if (!s)
		s = ultimo;
	while (s[i] != '\0')
	{
		if (search_char(d, s[i]) == 0 && s[i + 1] == '\0')
		{
			ultimo = s + i + 1;
			*ultimo = '\0';
			s = s + r;
			return (s);
		}
		else if (search_char(d, s[i]) == 0 &&
				search_char(d, s[i + 1]) == 0)
			i++;
		else if (search_char(d, s[i]) == 0 &&
				search_char(d, s[i + 1]) == 1)
		{
			ultimo = s + i + 1;
			*ultimo = '\0';
			ultimo++;
			s = s + r;
			return (s);
		}
		else if (search_char(d, s[i]) == 1)
		{
			r++;
			i++;
		}
	}
	return (NULL);
}
