#include <main.h>

/**
* _strcpy - copy string
* @dest: a string to be copied to
* @src: a string to be copied
* Return: dest string
*/
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
* _strcat - concatenate strings.
* @dest: a string to be copied to
* @src: a string to be copied
* Return: dest string
*/
char *_strcat(char *dest, char *src)
{
	int x = 0;
	int i = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[x] != '\0')
	{
		dest[i] = src[x];
		i++;
		x++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
* _strdup - duplicate string in new address
* @str: a string pointer
* Return: dest string
*/
char *_strdup(char *str)
{
	int i, x;
	char *dest;

	i = 0;

	if (str == NULL)
		return (NULL);

	while (str[i])
		i++;

	dest = malloc(sizeof(char) * i);

	if (dest == NULL)
		return (NULL);

	for (x = 0; str[x]; x++)
		dest[x] = str[x];

	dest[x] = '\0';
	return (dest);
}

/**
* _strcmp - compare between strings
* @s1: string
* @s2: string
* Return: (0) same || (!0) not same
*/
int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
	{
		return (0);
	}
	else
	{
		return (*s1 - *s2);
	}
}
