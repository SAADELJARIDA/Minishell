#include "minishell.h"

void    free_all(char *input)
{
    char    **temp;
    int     i;
    t_garbage_collector temp;
    while (g_free != NULL)
    {
        if (g_free->is_arrof_p == 1)
        {
            temp = g_free->d_content;
            i = 0;
            while (temp[i] != 0)
            {
                free(temp[i]);
                i++;
            }
            free(temp);
        }
        else
            free(g_free->content);
        temp = g_free;
        g_free = g_free->next;
        free(temp);
    }
    free(g_free);
}