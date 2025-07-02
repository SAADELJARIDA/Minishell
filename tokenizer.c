#include "minishell.h"

int	alloc_str(char *input, int *i, t_tokenizer **node)
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
			fill_the_node(*node, -1, *i, to_alloc);
			*i = *i + end;
			break ;
		}
		end++;
	}
	return (*i);
}

int	alloc_quote(int i, char *input, t_tokenizer **node)
{
	char	*to_alloc;

	if (!input[i])
		return (i);
	if (is_operator(input + i) == DOUBLE_QUOTE
		|| is_operator(input + i) == QUOTE)
	{
		*node = add_node(&((*node)->next));
		to_alloc = alloc_quote_help(input + i, &i);
		fill_the_node(*node, -1, i, to_alloc);
	}
	return (i);
}

int	alloc_operator(int	*i, char *input, t_tokenizer **node)
{
	if (!input[*i])
		return (*i);
	if (is_operator(input + *i) < 5 && is_operator(input + *i) > -1)
	{
		*node = add_node(&((*node)->next));
		fill_the_node(*node, is_operator(input + *i), *i, NULL);
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

	i = 0;
	head = add_node(&node);
	while (input[i])
	{
		if (input[i] == ' ')
		{
			i++;
			continue ;
		}
		i = alloc_str(input, &i, &node);
		i = alloc_quote(i, input, &node);
		i = alloc_operator(&i, input, &node);
		i++;
	}
	node->next = NULL;
	temp = head;
	head = head->next;
	free(temp);
	return (head);
}
