#include "minishell.h"

void    free_all(char *input)
{
    char    **temp;
    int     i;

    while (g_free != NULL)
    {
        if (g_free->is_arrof_p == 1)
        {
            temp = g_free->d_content;
            i = 0;
            while (temp[i])
            {
                free(temp[i]);
                i++;
            }
            free(temp);
        }
    }
    free(input);
}