#ifndef MINISHELL_H
# define MINISHELL_H

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
# define TRUE 1
# define FALSE 2


typedef struct s_garbage_collector
{
	int							is_arrof_p;
	char						*content;
	char						**d_content;
	struct s_garbage_collector	*next;
}				t_garbage_collector;

typedef enum e_operator
{
	LESS_LESS, // <<
	GREAT_GREAT, // >>
	PIPE, // |
	LESS, // <
	GREAT, // > 
	QUOTE,
	DOUBLE_QUOTE,
}				t_operator;

typedef struct s_lexer
{
	int				i;
	char			*str;
	t_operator		op;
	struct s_lexer	*next;
}				t_lexer;

extern t_garbage_collector		*g_free;//
void	free_all(char *input, t_lexer *tokens);//
void	save_garbage(char **tokens, int is_arr);//
int		is_operator(char *str);
/* TOKENIZER */
char	*alloc_quote_help(char *str, int *i);
void	print_op(t_operator op, char *str);//
void	fill_the_node(t_lexer *node, int op, int i, char *token);
t_lexer *tokenizer(char *input);
t_lexer *add_node(t_lexer **node);
#endif
