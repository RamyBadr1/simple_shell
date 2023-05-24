#include "main.h"

/**
* s_handler - handles commands
* @s: an integer
*/
void s_handler(int s)
{
	(void)s;
	write(STDOUT_FILENO, "\n$ ", 3);
}
