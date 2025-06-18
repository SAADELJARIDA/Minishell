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

static t_lexer	*token_list(char **tokens)
{
	t_lexer	*head;
	t_lexer	*node;
	int		i;

	head = add_node(&node);
	i = 0;
	while (tokens[i] != NULL)
	{
		fill_the_node(node, is_operator(tokens[i]), i, tokens[i]);
		i++;
		if (tokens[i] != NULL)
			node = add_node(&(node->next));
	}
	node->next = NULL;
	free(tokens);
	return (head);
}

t_lexer	*lexer(char *input)
{
	int     i;
	char    **tokens;
	t_lexer	*head;
	t_lexer *temp;
	i = 0;
	// reminder : split returns an arry of pointers.
	tokens = ft_split(input,' '); 
	head = token_list(tokens);
	temp = head;
	while (temp != NULL)
	{
		if (temp->op == -1)	
			printf("%s\n",temp->str);
		else
			printf("%u\n", temp->op);
		temp = temp->next;
	}
	return head;
}