/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 22:21:49 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/05/06 00:22:07 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parsing_quote(t_struct *data)
{
	int	i;
	int	found_squote;
	int	found_dquote;

	found_squote = 0;
	found_dquote = 0;
	i = 0;
	while (data->str[i])
	{
		if (data->str[i] == '\'')
			found_squote = !found_squote;
		else if (data->str[i] == '\"')
			found_dquote = !found_dquote;
		i++;
	}
	if (found_squote)
		printf("Syntax error: unclosed single quote\n");
	if (found_dquote)
		printf("Syntax error: unclosed double quote\n");
}
