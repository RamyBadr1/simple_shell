#include "main.h"


/**
* get_line - read the input
* @prompt: the shell sign
* @data: a pointer to a struct array
*/


void get_line(data_p *data, char *prompt)
{
char *i = NULL;
char *b = NULL;
size_t x = 0;
int n, v, a;

write(STDOUT_FILENO, prompt, _strlen(prompt));
n = a = getline(&b, &x, stdin);
if (n == EOF)
{
free(b);
exit(errno);
}
if (b[n - 1] == '\n')
b[n - 1] = '\0';

data->c_name = _strdup(b);

if (a >= 1)
{
i = malloc(sizeof(char *) * a);
data->toke = malloc(sizeof(char *) * a);
i = strtok(b, " \t \n ");
for (v = 0; i != NULL; v++)
{
data->toke[v] = _strdup(i);
i = strtok(NULL, " \t \n ");
}
free(i);
}
free(b);
}

/**
* shell_loop - the invinite loop of the shell
* @prompt: the shell sign
* @data: a pointer to a struct array
*/

void shell_loop(data_p *data, char *prompt)
{
int x = 0;

while (1)
{
get_line(data, prompt);
++data->counter;
if (data->toke[0])
{
x = _execute(data);
if (x != 0)
_print_error(x, data);
}
}
free_array(data->toke);
free_data(data);
}
