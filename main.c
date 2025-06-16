#include "minishell.h"

t_garbage_collector *g_free = 0;

int main()
{
        char    **tokens;
        char    *input;
        
        t_garbage_collector  *node = malloc(sizeof(t_garbage_collector));
        input = "\033[1;32m➜\033[0m\033[1;36m Minishell@damn:$\033[0m";
        tokens = lexer(input);
        node->is_arrof_p = 1;
        node->content = 0;
        node->d_content = tokens;
        node->next = NULL;
        g_free = node;
        int i = 0;
        while (tokens[i])
        {   
                printf("%s \n", tokens[i]);
                i++;
        }
        free_all(input);
        free(g_free);
}
