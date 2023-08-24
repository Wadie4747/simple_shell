#include "shell.h"

/**
 * *_memset - Fills memory with a constant byte.
 * @dest: The pointer to the memory area.
 * @byte: The byte to fill @dest with.
 * @num: The number of bytes to fill.
 *
 * Return: A pointer to the memory area @dest.
 */

char *_memset(char *dest, char byte, unsigned int num)
{
	unsigned int i;

	for (i = 0; i < num; i++)
		dest[i] = byte;
	return (dest);
}

/**
 * ffree - Frees an array of strings.
 * @str_arr: The array of strings to free.
 */
void ffree(char **str_arr)
{
	char **temp = str_arr;

	if (!str_arr)
		return;
	while (*str_arr)
		free(*str_arr++);
	free(temp);
}

/**
 * *_realloc - Reallocates a block of memory.
 * @ptr: Pointer to the previous allocated block.
 * @former_size: Size of the previous block.
 * @new_size: Size of the new block.
 *
 * Return: A pointer to the new block, or NULL on failure.
 */
void *_realloc(void *ptr, unsigned int former_size, unsigned int new_size)
{
	char *new_ptr;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == former_size)
		return (ptr);
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	former_size = former_size < new_size ? former_size : new_size;
	while (former_size--)
		new_ptr[former_size] = ((char *)ptr)[former_size];
	free(ptr);
	return (new_ptr);
}

/**
 * bfree - Frees a pointer and sets it to NULL.
 * @ptr: Address of the pointer to free.
 *
 * Return: 1 if the pointer was freed, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
