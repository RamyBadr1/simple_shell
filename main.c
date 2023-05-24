include "main.h"


/**
 * main - tha main function for the hsh shell
 * @argc: number og value;
 * @argv: array of argument
 * Return: 0
 */


int main(int argc, char *argv[])
{
	data_p strct, *data = &strct;

	set_data(data, argv);

	char *prompt = "";


	signal(SIGINT, s_handler);

	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1) && argc == 1)
	{
		prompt = "$ ";
	}
	shell_loop(data, prompt);

	return (0);
}

/**
 * set_data - set the struct array to their value
 * @data: a pointer to a struct array
 * @argv: the argument
 */


void set_data(data_p *data, char *argv[])
{
	int i;

	data->name = argv[0];
	data->toke = NULL;
	data->c_name = NULL;

	for (i = 0; environ[i]; i++)
	;

	data->env = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		data->env[i] = _strdup(environ[i]);
	}
	data->env[i] = NULL;
	environ = data->env;
}

