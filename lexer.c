#include "minishell.h"
static t_lexer	create_node(t_lexer *head)
{
	t_lexer *node;

	node = malloc(sizeof(t_lexer));
	if (node)
		exit(0);
		
}
static t_lexer	token_list(char **tokens)
{
	t_lexer	*head;
	t_lexer	*node;
	int		op;
	int		i;

	head = node;
	while (tokens[i] != NULL)
	{
		op = is_operator(tokens[i]);
		if (op != -1)
		{
			node->i = i;
			node->op = op;
			node->str = NULL;	
		}
		else
		{
			node->i = i;
			node->op = -1;
			node->str = tokens[i];	
		}
		i++;
		if (tokens[i] != NULL)
		{
			node->next = malloc(sizeof(t_lexer));
			node = node->next;
		}
	}
}
char    **lexer(char *input)
{
	int     i;
	char    **tokens;
	t_lexer	*node;
	t_lexer	*head;

	i = 0;
	tokens = ft_split(input,' ');
	save_garbage(tokens, 1);
	free(input);
	return head;
}