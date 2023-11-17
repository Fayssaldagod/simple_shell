#include "shell.h"

/**
 * *_strchr - It finds char in the strings.
 * @s: The string to be searched.
 * @c: The char being sought.
 *
 * Return: (s) pointer to memory area s.
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

/**
 * _putchar - It wil print 'c' to stdout.
 * @c: The character to be print'ed.
 *
 * Return: On success 1 and -1 on error.
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 *_puts - It will outputs the provided string.
 *@str: Strings to be printed.
 *
 * Return: None
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _strdup - It duplciate a string.
 * @str: Strings to be duplicated.
 *
 * Return: The Pointer to the duplicated strings.
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 * _strcpy - It replicates a string.
 * @dest: Destination.
 * @src: Source.
 *
 * Return: The pointer to the destination.
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

