#include "minishell.h"

int main()
{
    char    *input;

    while (True)
    {
        input = readline("\033[1;32m➜\033[0m\033[1;36m Minishell@damn:$\033[0m ");
        parse_input(input);
        free(input);
    }
}