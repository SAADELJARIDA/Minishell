#include "minishell.h"

int	token_fix(t_lexer *head)
{
	int	i;
	int	j;
	t_operator c;
	t_lexer		*temp;

	temp = head;
	while (temp != NULL)	
	{
		i = 0;
		while(temp->str[i])
		{
			c = temp->str[i];
			c = is_opprator(c);
			if (c == -1)
				continue;
			else if (c != 1 || c)
			{
				count_words(temp, i);
			}
		}
	}
}