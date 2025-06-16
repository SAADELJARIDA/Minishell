#include "minishell.h"

t_garbage_collector *g_free = 0;

int main()
{
        char                    **tokens;
        char                    *input;

        input = readline("\033[1;32m➜\033[0m\033[1;36m Minishell@damn:$\033[0m");
        tokens = lexer(input);
        save_garbage(tokens, 1);
        int i = 0;
        while (tokens[i])
        {   
                printf("%s \n", tokens[i]);
                i++;
        }
        free_all(input);
}