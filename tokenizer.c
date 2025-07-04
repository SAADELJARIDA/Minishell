#include "minishell.h"

int	alloc_str(char *input, int *i, t_tokenizer **node, int node_i)
{
	size_t		end;
	char		*to_alloc;
	char		c;
	t_operator	op;

	end = 0;
	while (input[*i + end] != '\0' && is_operator(input + *i + end) == -1)
	{
		c = input[*i + end + 1];
		op = is_operator(input + *i + end + 1);
		if (c == '\0' || c == ' ' || op != -1)
		{
			*node = add_node(&((*node)->next));
			to_alloc = ft_substr(input, *i, end + 1);
			fill_the_node_str(*node, node_i, to_alloc, -1);
			*i = *i + end;
			break ;
		}
		end++;
	}
	return (*i);
}

int	alloc_quote(int i, char *input, t_tokenizer **node, int node_i)
{
	char	*to_alloc;
	t_quote	quote_state;

	if (!input[i])
		return (i);
	quote_state = -1;
	if (is_operator(input + i) == DOUBLE_QUOTE
		|| is_operator(input + i) == QUOTE)
	{
		*node = add_node(&((*node)->next));
		if (i != 0 && input[i - 1] == ' ')
			quote_state	= SPACE_BEFORE; 
		to_alloc = alloc_quote_help(input + i, &i);
		if (input[i + 1] == ' ' && quote_state != -1)
			quote_state = SPACE_BEFORE_AFTER;
		else if (input[i + 1] == ' ' && quote_state == -1)
			quote_state = SPACE_AFTER;
		else if (input[i + 1] != ' ' && quote_state == -1)
			quote_state = NO_SPACE;
		fill_the_node_str(*node, node_i, to_alloc, quote_state);
	}
	return (i);
}

int	alloc_operator(int	*i, char *input, t_tokenizer **node, int node_i)
{
	if (!input[*i])
		return (*i);
	if (is_operator(input + *i) < 5 && is_operator(input + *i) > -1)
	{
		*node = add_node(&((*node)->next));
		fill_the_node_op(*node, is_operator(input + *i), node_i);
		if (is_operator(input + *i) < 2)
			*i += 1;
	}
	return (*i);
}

t_tokenizer *tokenizer(char *input)
{
	t_tokenizer	*head;
	t_tokenizer	*node;
	t_tokenizer	*temp;
	int		i;
	int 	node_i;

	i = 0;
	node_i = 0;
	head = add_node(&node);
	while (input[i])
	{

		if (input[i] == ' ')
		{
			i++;
			continue ;
		}
		i = alloc_str(input, &i, &node, node_i);
		i = alloc_quote(i, input, &node, node_i);
		i = alloc_operator(&i, input, &node, node_i);
		i++;
		node_i++;
	}
	node->next = NULL;
	temp = head;
	head = head->next;
	free(temp);
	return (head);
}