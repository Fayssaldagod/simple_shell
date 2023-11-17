#include "shell.h"

/**
 * _atoi - it will transform a string to an int.
 * @s: The string to be converted.
 *
 * Return: 0 if no numbers in string, converted number otherwise.
 */
int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
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

/**
 * _isalpha - it will verify either a character is an alphabetic character.
 * @c: The character to be examined.
 *
 * Return: 1 if 'c' is alphabetic, 0 if not
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * bfree - it will free the pointer and NULLs the address
 * @ptr: The address of pointer to be free'd.
 *
 * Return: 1 if free'd, 0 if not.
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

/**
 * ffree - it will free a string of strings.
 * @pp: The string of strings
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 **_memset - It will fill memory with constant byte.
 *@s: pointer to a memory area.
 *@b: byte that fills *s.
 *@n: The amount of bytes that will be filled.
 *Return: (s) a pointer to memory area s.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

