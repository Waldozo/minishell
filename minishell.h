/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:54:23 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/05/06 00:22:20 by wlarbi-a         ###   ########.fr       */
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
	NONE = -1,
	S_QUOTE,
	D_QUOTE,
	PIPE,
	WORD,
	REDIR,
	HEREDOC,
	PARENTHESIS,
	SPACES,
}					t_token;

typedef struct s_struct
{
	t_token			type;
	char			*str;
	struct s_struct	*next;
}					t_struct;

/*--------------------utils-----------------*/
int					ft_strlen(char *str);
int					ft_strcmp(const char *s1, const char *s2);
char				**ft_split(char const *s, char c);

/*------------------parsing-----------------*/

void				parsing(t_struct *data);
void				is_token(t_struct *data);

/*--------------parsing pipe----------------*/

int					utils_parse_pipe(t_struct *data, int i, int *found_pipe);
void				parse_error_pipe(t_struct *data);

/*--------------parsing redir----------------*/

void				parse_redir(t_struct *data);
int					utils_parse_redir(t_struct *data, int i, int *found_redir);
int					handle_redir(t_struct *data, int i, int *found_redir);

/*---------------parsing quote---------------*/

void				parsing_quote(t_struct *data);

#endif