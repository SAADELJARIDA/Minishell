/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 11:41:01 by sel-jari          #+#    #+#             */
/*   Updated: 2025/06/21 11:41:04 by sel-jari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*alloc_quote(char *str, int *i)
{
	int		len;
	char	*alc_str;

	len = 1;
	while (str[len] != '\"')
		len++;
	alc_str = malloc(len + 2);
	ft_strlcpy(alc_str, str, len + 2);
	*i = *i + len;

	return (alc_str);
}
// int	is_operator(char *str)
// {
// 	t_operator	op;

// 	if (ft_strncmp("<<", str, 2) == 0)
// 		op = LESS_LESS;
// 	else if (ft_strncmp(">>", str, 2) == 0)
// 		op = GREAT_GREAT;
// 	else if (ft_strncmp("|", str, 1) == 0)
// 		op = PIPE;
// 	else if (ft_strncmp("<", str, 1) == 0)
// 		op = LESS;
// 	else if (ft_strncmp(">", str, 2) == 0)
// 		op = GREAT;
// 	else if (ft_strncmp("\"", str, 1) == 0)
// 		op = DOUBLE_QUOTE;
// 	else if (ft_strncmp("\'", str, 1) == 0)
// 		op = QUOTE;
// 	else
// 		return (-1);
// 	return (op);
// }
// int main()
// {
// 	char *str = "echo saad                \"helloworld\"$PATH\"salam labas\"\"saad eddine eljarida\"";
// 	char *all;
// 	int i;
// 	int	end;
// 	char	*to_alloc;

// 	i = 0;
// 	while (str[i])
// 	{
// 		end = 0;
// 		if (str[i] == '\"')
// 		{
// 			all = alloc_quote(str + i, &i);
// 			printf("%s\n",all);
// 			free(all);
// 		}
// 		while(is_operator(str + i + end) == -1)
// 		{
// 			if (is_operator(str + i + end + 1) != -1)
// 			{
// 				to_alloc = ft_substr(str, i, end + 1);
// 				i = i + end;
// 				printf("to_alloc: %s\n",to_alloc);
// 				break;
// 			}
// 			end++;
// 		}
// 		i++;
// 	}
	
// }