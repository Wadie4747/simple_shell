#include "shell.h"

/**
 * clear_info - Initializes an info_t struct
 * @info: Address of the info_t struct to be initialized
 */

void clear_info(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * set_info - Initializes an info_t struct
 * @info: Address of the info_t struct to be initialized
 * @av: Argument vector (array of strings)
 */

void set_info(info_t *info, char **av)
{
	int i = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strtow(info->arg, " \t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (i = 0; info->argv && info->argv[i]; i++)
			info->argc = i;
		replace_alias(info);
		replace_vars(info);
	}
}

/**
 * free_info - Frees the fields of an info_t struct
 * @info: Address of the info_t struct whose fields need to be freed
 * @all: True if all fields need to be freed
 */

void free_info(info_t *info, int all)
{
	ffree(info->argv);
	info->argv = NULL;
	info->path = Null;
	if (all)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			free_list(&(info->env));
		if (info->history)
			free_list(&(info->history));
		if (info->alias)
			free_list(&(info->alias));
		ffre(info->environ);
		info->environ = NULL;
		bfree((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(indo->readfd);
		_putchar(BUF_FLUSH);
	}
}
