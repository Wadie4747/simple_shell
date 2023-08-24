#include "shell.h"

/**
 * **strtow - Splits a string into words, ignoring repeat delimiters.
 * @in_str: The input string.
 * @delim_str: The delimiter string.
 *
 * Return: A pointer to an array of strings, or NULL on failure.
 */
char **strtow(char *in_str, char *delim_str)
{
	int idx1, idx2, idx3, idx4, num_words = 0;
	char **result_array;

	if (in_str == NULL || in_str[0] == '\0')
		return (NULL);
	if (!delim_str)
		delimiter_str = " ";
	for (idx1 = 0; input_str[idx1] != '\0'; idx1++)
	{
		if (!is_delim(in_str[idx1], delim_str) &&
				(is_delim(in_str[idx1 + 1], delim_str) ||
				 !in_str[idx1 + 1]))
			num_words++;
	}
	if (num_words == 0)
		return (NULL);
	result_array = malloc((1 + num_words) * sizeof(char *));
	if (!result_array)
		return (NULL);
	for (idx1 = 0, idx2 = 0; idx2 < num_words; idx2++)
	{
		while (is_delim(in_str[idx1], delim_str))
			idx1++;
		idx3 = 0;
		while (!is_delim(in_str[idx1 + idx3], delim_str) &&
				in_str[idx1 + idx3])
			idx3++;
		result_array[idx2] = malloc((idx3 + 1) * sizeof(char));
		if (!result_array[idx2])
		{
			for (idx4 = 0; idx4 < idx2; idx4++)
				free(result_array[idx4]);
			free(result_array);
			return (NULL);
		}
		for (idx4 = 0; idx4 < idx3; idx4++)
			result_array[idx2][idx4] = in_str[idx1++];
		result_array[idx2][idx4] = '\0';
	}
	result_array[idx2] = NULL;
	return (result_array);
}

/**
 * **strtow2 - Splits a string into words using a single delimiter.
 * @in_str: The input string.
 * @delim: The delimiter character.
 *
 * Return: A pointer to an array of strings, or NULL on failure.
 */
char **strtow2(char *in_str, char delim)
{
	int idx1, idx2, idx3, idx4, num_words = 0;
	char **result_array;

	if (in_str == NULL || in_str[0] == '\0')
		return (NULL);
	for (idx1 = 0; in_str[idx1] != '\0'; idx1++)
	{
		if ((in_str[idx1] != delim && in_str[idx1 + 1] == delim) ||
				(in_str[idx1] != delim && !in_str[idx1 + 1]) ||
				in_str[idx1 + 1] == delim)
			num_words++;
	}
	if (num_words == 0)
		return (NULL);
	result_array = malloc((1 + num_words) * sizeof(char *));
	if (!result_array)
		return (NULL);
	for (idx1 = 0, idx2 = 0; idx2 < num_words; idx2++)
	{
		while (in_str[idx1] == delim && in_str[idx1] != delim)
			idx1++;
		idx3 = 0;
		while (in_str[idx1 + idx3] != delim && in_str[idx1 + idx3] &&
				in_str[idx1 + idx3] != delim)
			idx3++;
		result_array[idx2] = malloc((idx3 + 1) * sizeof(char));
		if (!result_array[idx2])
		{
			for (idx4 = 0; idx4 < idx2; idx4++)
				free(result_array[idx4]);
			free(result_array);
			return (NULL);
		}
		for (idx4 = 0; idx4 < idx3; idx4++)
			result_array[idx2][idx4] = in_str[idx1++];
		result_array[idx2][idx4] = '\0';
	}
	result_array[idx2] = NULL;
	return (result_array);
}
