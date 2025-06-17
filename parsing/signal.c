/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:59:01 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/05/29 07:32:12 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_sigint(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_replace_line("", 1);
	rl_on_new_line();
	rl_redisplay();
}

// ctr+\ il faut le faire dans les child, la sortie sera Quit (core dumped)
void	handle_sigquit(int sig)
{
	(void)sig;
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

//oublie pas d'enlever cette fonction avant de merge
int	cpy_env(t_struct *data, char **envp)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (envp[len])
		len++;
	data->env = malloc(sizeof(char *) * (len + 1));
	if (!data->env)
		return (0);
	while (envp[i])
	{
		data->env[i] = ft_strdup(envp[i]);
		// if (!data->env[i])
		// {
		// 	ft_free_array(data->env);
		// 	return (0);
		// }
		i++;
	}
	data->env[len] = NULL;
	return (1);
}

void	ft_env(t_struct *data, char **cmd)
{
	int	i;

	if (cmd[1])
	{
		ft_putstr_fd("env: ", 2);
		ft_putstr_fd("‘", 2);
		ft_putstr_fd(cmd[1], 2);
		ft_putstr_fd("‘", 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return ;
	}
	i = 0;
	while (data->env[i])
	{
		if (ft_strchr(data->env[i], '='))
			printf("%s\n", data->env[i]);
		i++;
	}
}

char	*get_env_value(char *key, char **envp)
{
	int		i;
	int		len;

	i = 0;
	len = strlen(key);
	while (envp[i])
	{
		if (!strncmp(envp[i], key, len) && envp[i][len] == '=')
			return (envp[i] + len + 1);
		i++;
	}
	return (NULL);
}

char	*append_to_result(char *res, char *add)
{
	char	*new;
	size_t	len;

	if (!res)
		return (strdup(add));
	len = strlen(res) + strlen(add);
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	strcpy(new, res);
	strcat(new, add);
	free(res);
	return (new);
}
char	*expand_variables(char *str, char **envp)
{
	int		i;
	int		start;
	int		in_sq;
	int		in_dq;
	char	*res;
	char	*key;
	char	*val;

	i = 0;
	in_sq = 0;
	in_dq = 0;
	res = NULL;
	while (str[i])
	{
		if (str[i] == '\'' && !in_dq)
		{
			in_sq = !in_sq;
			res = append_to_result(res, "\'");
			i++;
		}
		else if (str[i] == '\"' && !in_sq)
		{
			in_dq = !in_dq;
			res = append_to_result(res, "\"");
			i++;
		}
		else if (str[i] == '$' && !in_sq && str[i + 1])
		{
			start = ++i;
			while (str[i] && (str[i] == '_' || (str[i] >= 'A' && str[i] <= 'Z')
					|| (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')))
				i++;
			key = strndup(str + start, i - start);
			val = get_env_value(key, envp);
			free(key);
			if (val)
				res = append_to_result(res, val);
		}
		else
		{
			start = i;
			while (str[i] && str[i] != '$' && str[i] != '\'' && str[i] != '\"')
				i++;
			key = strndup(str + start, i - start);
			res = append_to_result(res, key);
			free(key);
		}
	}
	return (res);
}
