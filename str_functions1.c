#include "shell.h"

/**
 * _strcpy - Copies a string.
 * @destination: The destination buffer.
 * @source: The source string.
 *
 * Return: Pointer to the destination buffer.
 */

char *_strcpy(char *destination, char *source)
{
	int index = 0;

	if (destination == source || source == NULL)
		return (destination);
	while (source[index])
	{
		destination[index] = source[index];
		index++;
	}
	destination[index] = '\0';
	return (destination);
}

/**
 * _strdup - Duplicates a string.
 * @str: The string to duplicate.
 *
 * Return: Pointer to the duplicated string.
 */

char *_strdup(const char *str)
{
	int length = 0;
	char *result;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	result = malloc(sizeof(char) * (length + 1));
	if (!result)
		return (NULL);
	for (length++; length--;)
		result[length] = *--str;
	return (result);
}

/**
 * _puts - Prints an input string.
 * @str: The string to be printed.
 *
 * Return: Nothing.
 */

void _puts(char *str)
{
	int index = 0;

	if (!str)
		return;
	while (str[index] != '\0')
	{
		_putchar(str[index]);
		index++;
	}
}

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to print.
 *
 * Return: On success 1, on error -1, and errno is set appropriately.
 */

int _putchar(char c)
{
	static int bufferIndex;
	static char buffer[WRITE_BUFFER_SIZE];

	if (c == BUFFER_FLUSH || bufferIndex >= WRITE_BUFFER_SIZE)
	{
		write(1, buffer, bufferIndex);
		bufferIndex = 0;
	}
	if (c != BUFFER_FLUSH)
		buffer[bufferIndex++] = c;
	return (1);
}
