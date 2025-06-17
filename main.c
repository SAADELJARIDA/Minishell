#include "minishell.h"

t_garbage_collector *g_free;

int main()
{
        char                    **tokens;
        char                    *input;

        //signal_handler();
        input = readline("\033[1;32m➜\033[0m\033[1;36m Minishell@damn:$\033[0m");
        tokens = lexer(input);
        int i = 0;
        while (tokens[i])
        {   
                printf("%s \n", tokens[i]);
                i++;
        }
        free_all(input);
}