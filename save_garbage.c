#include "minishell.h"

/*this function make the node os it help me clear all the memory allocation easily*/
void    save_garbage(char **tokens, int is_arr)
{
    t_garbage_collector  *node = malloc(sizeof(t_garbage_collector));

    if (is_arr == 1)
    {
        node->is_arrof_p = 1;
        node->content = NULL;
        node->d_content = tokens;
        node->next = NULL;
    }
    else
    {
        node->is_arrof_p = 0;
        node->content = *tokens;
        node->d_content = NULL;
        node->next = NULL;
    }
    g_free = node;
}