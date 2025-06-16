# ifndef MINISHELL_H
#define MINISHELL_H

# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <linux/limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include "libft/libft.h"
# define True 1
# define False 2

char    **lexer(char *input);
typedef struct  s_garbage_collector
{
    int     is_arrof_p;
    char    *content;
    char    **d_content;
    struct s_garbage_collector *next;
}               t_garbage_collector;

extern t_garbage_collector *g_free;

#endif