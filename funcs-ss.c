#include "shell.h"

/**
 *_putsfd - outputs input string.
 * @str: The string to be printed.
 * @fd: The filedescriptor written to.
 *
 * Return: Number of characters displayed.
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}

/**
 * _putfd - will output 'c' to the given FD.
 * @c: The characters to be written.
 * @fd: The FD to be written to.
 *
 * Return: 1 on success.
 * On error, -1 is returned, and errno is set correctly.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _eputchar - will output c to stderr.
 * @c: The character to be written to.
 *
 * Return: upon success 1.
 * On error, -1 is returned, and errno is set correctly.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * dup_chars - It will duplicate chars.
 * @pathstr: The PATH's string.
 * @start: starting index.
 * @stop: terminate index.
 *
 * Return: Pointer to the new allocated buffer.
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}

/**
 * is_cmd - Tt will check if the file is an exe.
 * @info: The info's struct.
 * @path: Path to the file.
 *
 * Return: 1 when true, 0 if not.
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

