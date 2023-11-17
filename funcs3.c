#include "shell.h"

/**
 * populate_env_list - It will initializes env linked list.
 * @info: The structure containing possibles arguments.
 *
 * Return: Always 0.
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}

/**
 * _myunsetenv - It will delete environment variables.
 * @info: structs with potential args.
 *
 * Return: Always 0.
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too little arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * _mysetenv - It will create a new or modify environments.
 * @info: structs containing potential arguments.
 *
 * Return: Always 0.
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _getenv - It will obtains value of env variable.
 * @info: will structure with possible arguments.
 * @name: env var.
 *
 * Return: Value.
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _myenv - output currente env.
 * @info: Structs with possible args.
 *
 * Return: Always 0.
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

