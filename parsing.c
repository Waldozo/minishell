/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:13:50 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/05/03 14:52:28 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"

// void	is_space(t_struct *data)
// {
// 	int	i;

// 	i = 0;
// 	while (data->str[i])
// 	{
// 		if (data->str[i] == ' ' || data->str[i] == '\t' || data->str[i] == '\n')
// 		{
// 			i++;
// 		}
// 		else
// 		{
// 			break ;
// 		}
// 	}
// }

// void	is_quote(t_struct *data)
// {
// 	while (data->str)
// 	{
// 		if (data->str == '\'')
// 		{
// 			data->type = S_QUOTE;
// 		}
// 		else if (data->str == '\"')
// 		{
// 			data->type = D_QUOTE;
// 		}
// 		data->str = data->next;
// 	}
// }

// void	is_parenthesis(t_struct *data)
// {
// 	while (data->str)
// 	{
// 		if (data->str == "(" || data->str == ")")
// 		{
// 			data->type = PARENTHESIS;
// 		}
// 		data->str = data->next;
// 	}
// }

// void	is_pipe(t_struct *data)
// {
// 	while (data->str)
// 	{
// 		if (data->str == "|")
// 		{
// 			data->type = PIPE;
// 		}
// 		data->str = data->next;
// 	}
// }

// void	is_redir(t_struct *data)
// {
// 	while (data->str)
// 	{
// 		if (data->str == "<")
// 		{
// 			data->type = REDIR;
// 		}
// 		data->str = data->next;
// 	}
// }

// void	is_heredoc(t_struct *data)
// {
// 	while (data->str)
// 	{
// 		if (data->str == "<<")
// 		{
// 			data->type = HEREDOC;
// 		}
// 		data->str = data->next;
// 	}
// }

// void	is_word(t_struct *data)
// {
// 	while (data->str)
// 	{
// 		if (data->type != PARENTHESIS && data->type != S_QUOTE
// 			&& data->type != D_QUOTE && data->type != PIPE && data->type != REDIR
// 			&& data->type != HEREDOC)
// 		{
// 			data->type = WORD;
// 		}
// 		data->str = data->next;
// 	}
// }

// void	is_token(t_struct *data)
// {
// 	is_space(data);
// 	is_quote(data);
// 	is_parenthesis(data);
// 	is_pipe(data);
// 	is_redir(data);
// 	is_heredoc(data);
// 	is_word(data);
// }
// void	parsing(t_struct *data)
// {
// 	while (data)
// 	{
// 		is_token(data);
// 		data = data->next;
// 	}
// }
