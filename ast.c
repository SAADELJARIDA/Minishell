#include "minishell.h"

t_tokenizer *add_tree_node(t_tokenizer *token, int pipe_i)
{
	char 		*str;
	int			i;
	char		**cmd;
	t_tokenizer	*temp;

	str = count_to_alloc(token);
	if (ft_strncmp("echo", token->str, 5) == 0)
	{
		echo_handling();
	}
	i = 0;
	cmd = malloc(sizeof(char *) * pipe_i);
	while (i < pipe_i)
	{
		if (token->str != NULL)
			cmd[i] = token->str;
		else
			cmd[i] = token->op;
		i++;
		token++;
	}
	token = token->next;
	return (token);
}

t_ast	*ast_builder(t_tokenizer *token)
{
	t_ast		*tree_head;
	t_ast		*tree_node;
	char		*cmd;
	t_tokenizer	*cmd_head;

	cmd_head = token;
	check_no_pipe(token);
	tree_node = malloc(sizeof(t_ast));
	tree_head = tree_node;
	// free&exit
	while (token != NULL)
	{
		if (token->op == 0)
		{
			cmd_head = add_tree_node(cmd_head, token->i);
		}
	}
}
