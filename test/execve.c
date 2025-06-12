#include "../minishell.h"
#include <string.h>
int main()
{
    char    *input;
	char *arg[] = {"ls", NULL};

    while (True)
    {
        input = readline("\033[1;32m➜\033[0m\033[1;36m Minishell@damn:$\033[0m ");
		if (!strcmp(input, "ls"))
		{
			execve("/bin/ls",arg, NULL);
			free(input);
		}
    }
}
