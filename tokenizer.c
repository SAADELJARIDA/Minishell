#include "minishell.h"

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


t_lexer *tokenizer(char *input)
{
	size_t		end;
	char		*to_alloc;
	t_lexer	*head;
	t_lexer	*node;
	t_lexer *temp;
	int	i;

	i = 0;
	head = add_node(&node);
	while (input[i])
	{
		end = 0;
		if (input[i] == ' ')
		{
			i++;
			continue;
		}
		while(is_operator(input + i + end) == -1)
		{
			if (is_operator(input + i + end + 1) != -1 || input[i + end + 1] == ' ')
			{
				node =  add_node(&(node->next));
				to_alloc = ft_substr(input , i, end + 1);
				printf("%s\n",to_alloc);
				fill_the_node(node, is_operator(to_alloc), i, to_alloc);
				i = i + end;
				break;
			}
			end++;
		}
		if (!input[i])
			break;
		if (is_operator(input + i) == DOUBLE_QUOTE)
		{
			node =  add_node(&(node->next));
			to_alloc = alloc_quote(input + i, &i);
			fill_the_node(node, -1, i, to_alloc);
		}
		if (is_operator(input + i) < 5 && is_operator(input + i) > -1)
		{
			node =  add_node(&(node->next));
			fill_the_node(node, is_operator(input + i), i, NULL);
			if (is_operator(input + i) < 2)
				i+=1;
		}
	 	i++;
	}
	node->next=NULL;	
	temp = head;
	head = head->next;
	free(temp);
	temp = head;
	return head;
}
// int main()
// {
// 	toknizer("echo saad     >> \""    |    <<><|<<>><><>\"hell$PATHoworld\"$PATH\"salam labas\"\"saad eddine eljarida\"");
// }