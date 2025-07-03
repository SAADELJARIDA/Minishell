#include "minishell.h"

char *node_to_str(t_tokenizer *token)
{
	char *str;

	str = count_to_alloc(tokens);
	if (ft_strncmp("echo", token->char, 5) == 0)
	{
		echo_handling();
	}
	while (token->op != 0)
	{
		count_to_alloc(tokens);
	}
}

t_ast	*ast_builder(t_tokenizer *token)
{
	t_ast	*tree_head;
	t_ast	*tree_node;
	char	*cmd;

	tree_node = malloc(t_ast);
	tree_head = tree_node;
	// free&exit
	while (token != NULL)
	{
		str = node_to_str(token);
		if ()
		{

		}
	}
}
