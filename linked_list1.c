#include "shell.h"

/**
 * list_len - Determines the length of a linked list.
 * @h: Pointer to the first node.
 *
 * Return: Size of the list.
 */

size_t list_len(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
		h = h->next;
		count++;
	}
	return (count);
}

/**
 * list_to_strings - Returns an array of strings from the list->str.
 * @head: Pointer to the first node.
 *
 * Return: Array of strings.
 */

char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t count = list_length(head), i;
	char **str_array;
	char *str_copy;

	if (!head || !count)
		return (NULL);
	str_array = malloc(sizeof(char *) * (count + 1));
	if (!str_array)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str_copy = malloc(_strlen(node->str) + 1);
		if (!str_copy)
		{
			for (size_t j = 0; j < i; j++)
				free(str_array[j]);
			free(str_array);
			return (NULL);
		}
		str_copy = _strcpy(str_copy, node->str);
		str_array[i] = str_copy;
	}
	str_array[i] = NULL;
	return (str_array);
}

/**
 * print_list - Prints all elements of a list_t linked list.
 * @h: Pointer to the first node.
 *
 * Return: Size of the list.
 */

size_t print_list(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		count++;
	}
	return (count);
}

/**
 * node_starts_with - Returns the node whose string starts with a prefix.
 * @node: Pointer to the list head.
 * @prefix: String to match.
 * @ch: The next character after prefix to match.
 *
 * Return: The matching node or NULL.
 */
list_t *node_starts_with(list_t *node, char *prefix, char ch)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((ch == -1) || (*p == ch)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - Gets the index of a node.
 * @head: Pointer to the list head.
 * @node: Pointer to the node.
 *
 * Return: Index of the node or -1.
 */

ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t index = 0;

	while (head)
	{
		if (head == node)
			return (index);
		head = head->next;
		index++;
	}
	return (-1);
}
