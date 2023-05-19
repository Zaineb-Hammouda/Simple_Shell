#include "shell.h"

int main(int ac, char *av[])
{
	char *input = NULL;
	size_t n;
	ssize_t read;
	char **args;
	int interactive = isatty(STDIN_FILENO);

	if (interactive)
	{
	while (1)
	{
		write(1,"myShell$ ",9);
		read = getline(&input, &n, stdin);
		if(read == -1)
		{
			write(1,"\n",1);
			exit(0);
		}
		if (strcmp(input,"\n") == 0)
			continue;

		args = arg_sep(input);
		if (args[0] == NULL)
			continue;

		execmd(args, av, input, 1);
 	}
	}
	else
	{
		while (getline(&input, &n, stdin) > 0)
		{
			args = arg_sep(input);
			if (args[0] == NULL)
				exit(0);
                	execmd(args, av, input, 0);
		}

	}
	return 0;
}
