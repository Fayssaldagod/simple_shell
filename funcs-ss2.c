#include "shell.h"

/**
 * _strcat - it will combine the two strings.
 * @dest: the destination's buffer.
 * @src: source buffer.
 *
 * Return: pointer to the destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

/**
 * starts_with - It verifies if the needle begins with a haystack.
 * @haystack: The string to be examined.
 * @needle: substring to be located.
 *
 * Return: Next Address of the character of haystack or NULL.
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcmp - It performs a comparison of two strings.
 * @s1: The 1st string.
 * @s2: The 2nd string.
 *
 * Return: Appropriate results.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * _strlen - it provides the length of the strings.
 * @s: The string's length to be checked!
 *
 * Return: Int length of string.
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 *_eputs - It will output the provided string.
 * @str: The string to be printed.
 *
 * Return: None.
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

