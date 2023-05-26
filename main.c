#include "main.h"

/**
 * main - main function
 * @argc: argc length
 * @argv: argv array
 * Return: 0 on success || 1 on error
 */
int main(int argc, char **argv)
{
	info_t information[] = { INFO_INIT };
	int filedescriptor = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (filedescriptor)
			: "r" (filedescriptor));

	if (argc == 2)
	{
		filedescriptor = open(argv[1], O_RDONLY);
		if (filedescriptor < 0)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(argv[0]);
				_eputs(": 0: Can't open ");
				_eputs(argv[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}

			return (EXIT_FAILURE);
		}
		information->readfd = filedescriptor;
	}
	populate_env_list(information);
	read_history(information);
	hsh(information, argv);
	return (EXIT_SUCCESS);
}
