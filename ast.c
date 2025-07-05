#include "minishell.h"

t_ast *add_tree_node(void)
{
	t_ast	*tree_node;	

	tree_node = malloc(sizeof(t_ast));
	if (tree_node == NULL)
	{
		// free_and_exit_error();
		return (NULL);
	}
	tree_node->type = -1;
	tree_node->rdc = -1;
	tree_node->cmd_line = NULL;
	tree_node->right = NULL;
	tree_node->left = NULL;
	return (tree_node);
}

t_tokenizer *fill_tree_node(t_tokenizer *cmd_line)
{
	t_ast			*tree_node;
	t_redirections	*rdc;

	tree_node = malloc(sizeof(t_ast));
	tree_node->type = CMD;
	if (ft_strncmp("echo", cmd_line->str, 5) == 0)
	{
		echo_handling();
	}
	tree_node->cmd = cmd_line->str;
	tree_node->cmd_line = cmd_line;
	rdc = malloc(sizeof(t_redirections));
	tree_node->rdc = rdc;
	while (cmd_line->str != NULL && cmd_line->str[0] != '|')
	{
		if (is_operator(cmd_line->op) < PIPE)
		{
			if (is_operator(cmd_line->op) == LESS_LESS)
				//the herdoc function TODO
			rdc = rdc->next;
			rdc = malloc(sizeof(t_redirections));	
			rdc->type = cmd_line->op;
			if (ft_isalpha(cmd_line->next->str[0]) != 0)
			{
				rdc->str = cmd_line->next->str;
			}
			else
			{
				//free_and_exit error;
				return (NULL)
			}
			cmd_line = cmd_line->next->next;
		}
	}
	return (tree_node);
}

t_ast	*ast_builder(t_tokenizer *token)
{
	t_ast		*tree_head;
	t_ast		*tree_node;
	char		*cmd;
	t_tokenizer	*cmd_head;

	cmd_head = token;
	// check_no_pipe(token);
	tree_node = add_tree_node();
	tree_head = tree_node;
	// free&exit();
	while (token != NULL)
	{
		if (token->next == NULL)
		{
			tree_node->left = fill_tree_node(cmd_head);
			cmd_head = token->next;
		}
		if (token->op == PIPE)
		{
			tree_node->type = PIPE;
			tree_node->right = fill_tree_node(cmd_head);
			tree_node = tree_node->left;
			cmd_head = token->next;
		}
		token = token->next;
	}
}
