#include "minishell.h"

void    free_all(char *input)
{
    char    **temp;
    int     i;
    t_garbage_collector *tmp;
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
        tmp = g_free;
        g_free = g_free->next;
        free(tmp);
    }
    free(input);
}