#include "main.h"
/**
* _execute - execute simple shell.
* @data: a struct
* Return: (0) SUCCESS || other int for failure
*/
int _execute(data_p *data)
{
	int status, x = handl_builtin(data);
	pid_t pidd;

	if (x)
		return (x);
	x = get_locat(data);
	if (x)
		return (x);
	if (!x)
	{
		pidd = fork();
		if (pidd == -1)
		{
			perror(data->name);
			exit(EXIT_FAILURE);
		}
		if (pidd == 0)
		{
			x = execve(data->toke[0], data->toke, data->env);
			if (x == -1)
			{
				perror(data->name);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status))
			{
				errno = WEXITSTATUS(status);
			}
			else if (WIFSIGNALED(status))
			{
				errno = 128 + WTERMSIG(status);
			}
		}
	}
	return (0);
}
