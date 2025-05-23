/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:54:23 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/05/23 16:46:11 by wlarbi-a         ###   ########.fr       */
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
	REDIR_IN,
	REDIR_OUT,
	APPEND,
	HEREDOC,
	PARENTHESIS,
	SPACES,
	WORD_D_QUOTES,
	WORD_S_QUOTES,
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
char				**ft_split(const char *s, char c);
char				*ft_strchr(char *str, int n);
char				*ft_strdup(char *src);
size_t				ft_strcpy(char *dst, char *src);
size_t				ft_strcat(char *dst, char *src);
size_t				ft_strlcpy(char *dst, char *src, size_t size);
char				*ft_strjoin(char *s1, char *s2);

/*------------------parsing-----------------*/

int					parsing(t_struct *data);
void				is_token(t_struct *data);
int					identify_special_token(t_struct *data, int i);
int					identify_redirection(t_struct *data, int i);

/*--------------parsing pipe----------------*/

int					utils_parse_pipe(t_struct *data, int i, int *found_pipe);
int					parse_error_pipe(t_struct *data);

/*--------------parsing redir----------------*/

int					parse_redir(t_struct *data);
int					utils_parse_redir(t_struct *data, int i, int *found_redir);
int					handle_redir(t_struct *data, int i, int *found_redir);

/*---------------parsing quote---------------*/

int					parsing_quote(t_struct *data);

/*--------------------path------------------*/

char				*find_path(char *cmd, char **paths);
void				free_paths(char **paths);

/*---------------special tokens-------------*/

void				free_token_list(t_struct *start);
t_struct			*create_token(const char *str, int len, t_token type);
int					token_init(t_struct *data);
void				tokenize_string(t_struct *data, int i);
void				token_append(t_struct *data);

/*-----------------handle------------------*/

void				handle_space_token(char *s, int *i, t_struct **cur);
void				handle_word_token(char *s, int *i, t_struct **cur);
void				handle_special_tokens(char *s, int *i, t_struct **cur);
void				append_and_advance(t_struct **cur, t_struct *new);
void				handle_redir_token(char *s, int *i, t_struct **cur);
void				handle_quotes(char *s, int *i, t_struct **cur);
/*-----------------word quote------------------*/

void				word_quote(t_struct *data, int *i, t_struct **cur);
void				handle_word_d_quotes(t_struct *data, int *i,
						t_struct **cur);
void				handle_word_s_quotes(t_struct *data, int *i,
						t_struct **cur);

/*-----------------fusion token------------------*/

void				echo_fusion(t_struct *data);

#endif