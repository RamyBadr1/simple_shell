#include "main.h"

/**
* _print - print string to the error standered
* @str: string pointer
* Return: the string
*/

int _print(char *str)
{
return (write(STDERR_FILENO, str, _strlen(str)));
}

/**
* _print_error - check the number and print it.
* @error: error code
* @data: a pointer to a struct array
* Return: 0
*/

int _print_error(int error, data_p *data)
{
if (error == 127)
{
_print(data->name);
_print(": ");
_print(data->c_name);
_print(": not found\n");
}
else if (error == 2)
{
_print(data->name);
_print(": ");
_print(data->toke[0]);
_print(": Illegal number: ");
}
else if (error == 126)
{
_print(data->name);
_print(": ");
_print(data->c_name);
_print(": Permission denied\n");
}
return (0);
}
