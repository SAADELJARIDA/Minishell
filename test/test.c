#include "minishell.h"

int main()
{
	char *input = readline("hellow: ");
	free(input);
}
