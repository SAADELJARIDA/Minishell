#include "minishell.h"

int	is_operator(char *str)
{
	if (ft_strncmp("|", str, 2) == 0)
		return PIPE;
	else if (ft_strncmp("<", str, 2) == 0)
		return LESS;
	else if (ft_strncmp(">", str, 2) == 0)
		return 1;
	else if (ft_strncmp("<<", str, 2) == 0)
		return 1;
	else if (ft_strncmp(">>", str, 2) == 0)
		return 1;
}
static void	fill_the_node(t_lexer *node, int op, int i, char *token)
{
	if (op != -1)
	{
		node->op = op;
		node->str = NULL;	
	}
	else
	{
		node->op = -1; // -1 if it's no an operator 
		node->str = token;	
	}
	node->i = i;
}

static t_lexer *add_node(t_lexer **node)
{
	*node = malloc(sizeof(t_lexer));
	if (*node == NULL)
	{
		// free_and_exit();
		exit(0);
	}
	return *node;
}

static t_lexer	*token_list(char **tokens)
{
	t_lexer	*head;
	t_lexer	*node;
	int		op;
	int		i;

	head = add_node(&node);
	while (tokens[i] != NULL)
	{
		op = is_operator(tokens[i]);
		fill_the_node(node, op, i, tokens[i]);
		i++;
		if (tokens[i] != NULL)
			node = add_node(node);
	}
}
t_lexer	*lexer(char *input)
{
	int     i;
	char    **tokens;
	t_lexer	*head;

	i = 0;
	// reminder : split returns an arry of pointers.
	tokens = ft_split(input,' '); 
	head = token_list(tokens);
	free(tokens);
	save_garbage(tokens, 1);
	free(input);
	return head;
}