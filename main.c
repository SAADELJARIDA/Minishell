#include "minishell.h"

t_garbage_collector *g_free = 0;
int main()
{
    char    *input;
    char    **tokens;
    char    *test;


        test = "hello world how are you";
        tokens = lexer(test);
        int i = 0;
        while (tokens[i])
        {
       
                printf("%s", *tokens);
                i++;
            
        }

}
