/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:54:23 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/05/02 19:07:49 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_token
{
	S_QUOTE,
	D_QUOTE,
	PIPE,
	WORD,
	REDIR,
	HEREDOC,
	PARENTHESIS,
}			t_token;

typedef struct s_struct
{
	t_token type;
	char	*str;
	struct s_struct *next;
}			t_struct;

/*--------------------utils-----------------*/
int			ft_strlen(char *str);

#endif