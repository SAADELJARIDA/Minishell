#include "minishell.h"
int	is_operator(char *str)
{
	t_operator	op;

	if (ft_strncmp("|", str, 2) == 0)
		op = PIPE;
	else if (ft_strncmp("<", str, 2) == 0)
		op = LESS;
	else if (ft_strncmp(">", str, 2) == 0)
		op = GREAT;
	else if (ft_strncmp("<<", str, 2) == 0)
		op = LESS_LESS;
	else if (ft_strncmp(">>", str, 2) == 0)
		op = GREAT_GREAT;
	else if (ft_strncmp("\"", str, 2) == 0)
		op = DOUBLE_QUOTE;
	else if (ft_strncmp("\'", str, 2) == 0)
		op = QUOTE;
	else
		return (-1);
	return (op);
}

static void	fill_the_node(t_lexer *node, int op, int i, char *token)
{
	node->i = i;
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
}

static t_lexer *add_node(t_lexer **node)
{
	*node = malloc(sizeof(t_lexer));
	if (*node == NULL)
	{
		// free_and_exit();
		exit(0);
	}
	return (*node);
}


int	toknizer(char *input)
{
	size_t		start,end;
	char		c;
	char		*to_alloc;
	int			count;
	t_operator	op;
	t_lexer	*head;
	t_lexer	*node;

	head = add_node(&node);
	start = 0;
	while (input[start])
	{
		end = 0;
		c = input[start];
		op = is_opperator(c);
		if (c == ' ')
			start++;
		while (op == -1 || c != ' ')
			end++;
		to_alloc = ft_substr(input, start, end);
		fill_the_node(node, is_operator(to_alloc), start, to_alloc);
	}
}