/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenkaci <fbenkaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:23:24 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/06/19 16:38:27 by fbenkaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t g_signal_status = 0;

void	free_tokens(t_struct *tokens)
{
	t_struct	*tmp;

	while (tokens)
	{
		if (tokens->env)
			ft_free_array(tokens->env);
		tmp = tokens->next;
		if (tokens->str)
			free(tokens->str);
		free(tokens);
		tokens = tmp;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_struct	*data;
	// t_struct	*tmp;
	t_cmd		*cmd;
	t_exec		*exec;

	// int			flag;
	// t_cmd *prev_cmd = NULL;
	(void)argv;
	// tmp = NULL;
	data = NULL;
	exec = malloc(sizeof(t_exec));
	if (!exec)
		return (1);
	// exec->last_status = 0;
	if (argc != 1)
	{
		printf("Error: need only one argument\n");
		free(exec);
		return (1);
	}
	data = (t_struct *)malloc(sizeof(t_struct));
	if (!data)
	{
		perror("Error allocating memory");
		free(exec);
		return (1);
	}
	if (cpy_env(data, envp) == -1)
	{
		free(exec);
		free(data);
		return (1);
	}
	data->exec = exec;
	exec->last_status = 0;
	while (1)
	{
		exec->last_status = g_signal_status;
		g_signal_status = 0;
		signal(SIGINT, handle_sigint); // Je remplace le comportement de ctrl+c par le mien
		signal(SIGQUIT, SIG_IGN); // je capture le signal quit et je lui dis de l'ignore dans le parent pour éviter le core dumped. Mon shell ne doit pas crasher.
		data->str = readline("💻 minishell > ");
		if (data->str == NULL)
		{
			ft_putstr_fd("exit\n", STDOUT_FILENO);
			break ;
		}
		if (ft_strlen(data->str) > 0)
		{
			add_history(data->str);
			if (parsing(data))
			{
				// tmp = data->next;
				// while (tmp)
				// {
				// 	printf("{%d -> %s}\n", tmp->type, tmp->str);
				// 	tmp = tmp->next;
				// }
				cmd = create_cmd_from_tokens(&data->next, data->env, exec);
				if (!cmd)
				{
					free_tokens(data->next);
					ft_free_array(data->env);
					free(data->str);
					free(exec);
					free(data);
					return (1);
				}
				execution(cmd, exec, &data);
				free_all_cmd(cmd);
				free_tokens(data->next);
			}
		}
	}
	ft_free_array(data->env);
	free(data->str);
	free(exec);
	free(data);
	return (0);
}
