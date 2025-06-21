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


t_lexer *toknizer(char *input)
{
	size_t		start,end;
	char		c;
	char		*to_alloc;
	int			count;
	t_operator	op;
	t_lexer	*head;
	t_lexer	*node;
	int	i;

	start = 0;
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
				fill_the_node(node, is_operator(to_alloc), i, to_alloc);
				printf("%s\n" ,node->str);
				i = i + end;
				break;
			}
			end++;
		}
		if (is_operator(input + i) == DOUBLE_QUOTE)
		{
			node =  add_node(&(node->next));
			to_alloc = alloc_quote(input + i, &i);
			fill_the_node(node, -1, i, to_alloc);
			printf("%s\n",node->str);
		}
		printf("is op: %d \n",is_operator("<<"));
		if (is_operator(input + i) < 5 && is_operator(input + i) > -1)
		{
			printf("the char : %c\n",input[i]);
			node =  add_node(&(node->next));
			fill_the_node(node, is_operator(input + i), i, NULL);
			printf("the op:%d\n",node->op);
		}
	 	i++;
	}
	return head;
}
int main()
{
	toknizer("echo saad                \"helloworld\"$PATH\"salam labas\"\"saad eddine eljarida\"");
}