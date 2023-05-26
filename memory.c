#include "main.h"

/**
 * bfree - free allocated memory
 * @pointer: address of the pointer to free
 * Return: 1 || 0.
 */
int bfree(void **pointer)
{
	if (pointer != NULL && *pointer != NULL)
	{
		free(*pointer);
		*pointer = NULL;
		return (1);
	}
	return (0);
}
