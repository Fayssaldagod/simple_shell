#include "shell.h"

/**
 * _myhelp - It changes the directory of the process.
 * @info: A structure with potential arguments.
 *
 * Return: Always 0.
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("Function not implemented yet \n");
	if (0)
		_puts(*arg_array);
	return (0);
}

/**
 * _mycd - it will modiife the directory of the process.
 * @info: The structure containing possible arguments.
 *
 *  Return: Always 0.
 */
int _mycd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getpwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret =
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret =
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "Can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myexit - Will terminate shell
 * @info: The structure containing the potential arguments.
 *
 *  Return: Exits with an exit status.
 */
int _myexit(info_t *info)
{
	int exitcheck;

	if (info->argv[1])
	{
		exitcheck = _erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * is_delim - It will determine if a character is a delimiter.
 * @c: The character to examine.
 * @delim: The delimiter string.
 *
 * Return: 1 if the character is a delimiter, 0 if not.
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * interactive - it will determines if shell operates in interactive mode.
 * @info: the address of the structure.
 *
 * Return: 1 if the shell is in interactive mode, 0 if not.
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

