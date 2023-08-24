#include "shell.h"

/**
 * _strncpy - Copies a string up to a specified length.
 * @destination: The destination string to copy to.
 * @source: The source string to copy from.
 * @n: The maximum number of characters to copy.
 *
 * Return: A pointer to the beginning of the destination string.
 */

char *_strncpy(char *destination, char *source, int n)
{
	int index_dest = 0;
	char *result = destination;

	while (source[index_dest] != '\0' && index_dest < n - 1)
	{
		destination[index_dest] = source[index_dest];
		index_dest++;
	}
	if (index_dest < n)
	{
		int index_fill = index_dest;

		while (index_fill < n)
		{
			destination[index_fill] = '\0';
			index_fill++;
		}
	}
	return (result);
}

/**
 * _strncat - Concatenates two strings up to a specified length.
 * @destination: The destination string to concatenate to.
 * @source: The source string to concatenate from.
 * @n: The maximum number of bytes to be used.
 *
 * Return: A pointer to the beginning of the destination string.
 */

char *_strncat(char *destination, char *source, int n)
{
	int index_dest = 0;
	int index_src = 0;
	char *result = destination;

	while (destination[index_dest] != '\0')
		index_dest++;
	while (source[index_src] != '\0' && index_src < n)
	{
		destination[index_dest] = source[index_src];
		index_dest++;
		index_src++;
	}
	if (index_src < n)
		destination[index_dest] = '\0';
	return (result);
}

/**
 * _strchr - Locates a character in a string.
 * @str: The string to search.
 * @ch: The character to look for.
 *
 * Return: A pointer to the first occurrence of the character,
 * or NULL if not found.
 */

char *_strchr(char *str, char ch)
{
	do {
		if (*str == ch)
			return (str);
	} while (*str++ != '\0');
	return (NULL);
}
