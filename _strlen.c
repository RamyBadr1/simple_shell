#include "main.h"

/**
* _strlen - a string length
* @s: a pointer to a string
* Return: the length of a given string;
*/
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	;

	return (i);
}
