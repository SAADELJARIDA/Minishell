#include "minishell.h"

char    **lexer(char *input)
{
    char **tokens;
    tokens = ft_split(input,' ');
    return tokens;
}