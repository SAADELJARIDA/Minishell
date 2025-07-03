#include "minishell.h"

void    free_all(char *input, t_tokenizer *tokens)
{
	t_tokenizer	*temp;
	// int     i;
    //t_garbage_collector *tmp;
    // char    **temp;
    // while (g_free != NULL)
    // {
    //     if (g_free->is_arrof_p == 1)
    //     {
    //         temp = g_free->d_content;
    //         i = 0;
    //         while (temp[i] != 0)
    //         {
    //             free(temp[i]);
    //             i++;
    //         }
    //         free(temp);
    //     }
    //     else
    //         free(g_free->content);
    //     tmp = g_free;
    //     g_free = g_free->next;
    //     free(tmp);
    // }
	temp = tokens;
	while (tokens != NULL)
	{
		if (tokens->str != NULL)	
			free(tokens->str);
		temp = tokens;
		tokens = tokens->next;
		free(temp);	
	}
    free(input);
}
