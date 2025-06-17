#include "minishell.h"

t_garbage_collector *g_free;

int main()
{

	char	*input;
	t_lexer *tokens;

	//signal_handler();
	input = readline("\033[1;32m➜\033[0m\033[1;36m Minishell@damn:$\033[0m");
	tokens = lexer(input);
	while (tokens != NULL)
	{
		if (tokens->op == -1)
	        printf("%s \n",	tokens->str);
		tokens = tokens->next;
	}
	free_all(input);
}