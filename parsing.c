/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:13:50 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/05/13 17:05:04 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	utils_token(t_struct *data, int i)
{
	while (data->str[i] && data->str[i] != '\'' && data->str[i] != '\"'
		&& data->str[i] != '(' && data->str[i] != ')' && data->str[i] != '|'
		&& data->str[i] != ' ' && data->str[i] != '<')
	{
		data->type = WORD;
		i++;
	}
	i--;
	return (i);
}

int	identify_redirection(t_struct *data, int i)
{
	if (data->str[i] == '>')
	{
		if (data->str[i + 1] == '>')
			data->type = APPEND;
		else
			data->type = REDIR_OUT;
	}
	else if (data->str[i] == '<')
	{
		if (data->str[i + 1] == '<')
			data->type = HEREDOC;
		else
			data->type = REDIR_IN;
	}
	return (i);
}

int	identify_special_token(t_struct *data, int i)
{
	if (data->str[i] == '\'')
		data->type = S_QUOTE;
	else if (data->str[i] == '\"')
		data->type = D_QUOTE;
	else if (data->str[i] == '(' || data->str[i] == ')')
		data->type = PARENTHESIS;
	else if (data->str[i] == '|')
		data->type = PIPE;
	else if (data->str[i] == ' ')
		data->type = SPACES;
	else if (data->str[i] == '>' || data->str[i] == '<')
		i = identify_redirection(data, i);
	else
		return (utils_token(data, i));
	return (i);
}

void	is_token(t_struct *data)
{
	int	i;

	i = -1;
	while (++i, data->str[i])
	{
		identify_special_token(data, i);
	}
}

void	parsing(t_struct *data)
{
	if (!data || !data->str)
		return ;
	data->type = NONE;
	is_token(data);
	parsing_quote(data);
	parse_error_pipe(data);
	parse_redir(data);
	token_append(data);
}
