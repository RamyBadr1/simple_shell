#include "main.h"


/**
* exit_shell - exit the shell
* @data: a pointer to a struct array
*/

void exit_shell(data_p *data)
{
free_data(data);
exit(0);
}

/**
* print_env - print the enviromint variable
*/

void print_env(void)
{
int x = 0;
char **env = environ;

while (env[x])
{
write(STDOUT_FILENO, (const void *)env[x], _strlen(env[x]));
write(STDOUT_FILENO, "\n", 1);
x++;
}
}

/**
* handl_builtin - handle th builtin command
* @data: a pointer to a struct array
* Return: 0;
*/

int handl_builtin(data_p *data)
{
builtin built = {"env", "exit"};

if (_strcmp(data->c_name, built.env) == 0)
{
print_env();
return (1);
}
else if (_strcmp(data->c_name, built.exit) == 0)
{
exit_shell(data);
return (1);
}
return (0);
}

