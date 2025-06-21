#include "minishell.h"

t_garbage_collector *g_free;

int main()
{

	char	*input;
	t_lexer *tokens;
	t_lexer *temp;

	//signal_handler();
	input = readline("\033[1;32m➜\033[0m\033[1;36m Minishell@damn:$\033[0m");
	//check_quo_error();
	//fix_input(input);
	tokens = tokenizer(input);
	temp = tokens;
	printf("_____________________\n");
	while (temp != NULL)
	{
		if (temp->op == -1)	
			printf("%s\n",temp->str);
		else
			print_op(temp->op, temp->str);
		temp = temp->next;
	}
}