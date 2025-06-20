#include "minishell.h"

t_garbage_collector *g_free;

int main()
{

	char	*input;
	t_lexer *tokens;

	//signal_handler();
	input = readline("\033[1;32m➜\033[0m\033[1;36m Minishell@damn:$\033[0m");
	check_quo_error();
	fix_input(input);
	tokens = lexer(input);
	free_all(input);
}