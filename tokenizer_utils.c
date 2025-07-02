#include "minishell.h"

int	is_operator(char *str)
{
	t_operator	op;

	if (ft_strncmp("<<", str, 2) == 0)
		op = LESS_LESS; //0
	else if (ft_strncmp(">>", str, 2) == 0)
		op = GREAT_GREAT; //1
	else if (ft_strncmp("|", str, 1) == 0)
		op = PIPE; //2
	else if (ft_strncmp("<", str, 1) == 0)
		op = LESS; //3
	else if (ft_strncmp(">", str, 1) == 0)
		op = GREAT; //4
	else if (ft_strncmp("\"", str, 1) == 0)
		op = DOUBLE_QUOTE; //5
	else if (ft_strncmp("\'", str, 1) == 0)
		op = QUOTE; //6
	else
		return (-1);
	return (op);
}

// int	is_quotes(char *str)
// {
// 	if (*(str) == '<' && *(str + 1) == '<'
// 		|| *(str) == '>' && *(str + 1) == '>' )
// 		return (2);
// 	return (1);
// }

char	*alloc_quote_help(char *str, int *i)
{
	int		len;
	char	*alc_str;
	char	c;

	len = 1;
	c = *str;
	while (str[len] != c)
		len++;
	alc_str = malloc(len + 2);
	ft_strlcpy(alc_str, str, len + 2);
	*i = *i + len;
	return (alc_str);
}

void	print_op(t_operator op, char *str)
{
	if (op == 0)
		printf("<<\n");
	else if (op == 1)
		printf(">>\n");
	else if (op == 2)
		printf("|\n");
	else if (op == 3)
		printf("<\n");
	else if (op == 4)
		printf(">\n");
	else if (op == 5)
		printf("\"\n");
	else if (op == 6)
		printf("\'\n");
	else
		printf("something else");
}

void	fill_the_node(t_tokenizer *node, int op, int i, char *token)
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

t_tokenizer	*add_node(t_tokenizer **node)
{
	*node = malloc(sizeof(t_lexer));
	if (*node == NULL)
	{
		// free_and_exit();
		exit(0);
	}
	(*node)->next = NULL;
	return (*node);
}
