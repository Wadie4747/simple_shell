#include "shell.h"

/**
 * check_interactive - Checks if the shell is in interactive mode.
 * @info: Pointer to the info_t structure.
 *
 * Return: 1 if in interactive mode, 0 otherwise.
 */
int check_interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delimiter - Checks if a character is a delimiter.
 * @ch: The character to check.
 * @delim: The delimiter string.
 *
 * Return: 1 if true, 0 if false.
 */
int is_delimiter(char ch, char *delim)
{
	while (*delim)
	{
		if (*delim++ == ch)
			return (1);
	}
	return (0);
}

/**
 * _isalpha - Checks if a character is alphabetic.
 * @ch: The character to check.
 *
 * Return: 1 if @c is an alphabet character, 0 otherwise.
 */
int _isalpha(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - Converts a string to an integer.
 * @str: The string to be converted.
 *
 * Return: 0 if no numbers in the string, the converted number otherwise.
 */
int _atoi(char *str)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; str[i] != '\0' && flag != 2; i++)
	{
		if (str[i] == '-')
			sign *= -1;
		if (str[i] >= '0' && str[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (str[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (sign == -1)
		output = -result;
	else
		output = result;
	return (output);
}
