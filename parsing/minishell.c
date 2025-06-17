/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:23:24 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/05/29 07:50:23 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_struct	*data;
	t_struct	*tmp;
	char		**cmd;
	// char		*input;
	char		*expanded;

	(void)argv;
	tmp = NULL;
	data = NULL;
	if (argc != 1)
	{
		printf("Error: need only one argument\n");
		return (1);
	}
	data = (t_struct *)malloc(sizeof(t_struct));
	if (!data)
	{
		perror("Error allocating memory");
		return (1);
	}
	cmd = malloc(sizeof(int) * 100);
	cpy_env(data, envp);
	while (1)
	{
		signal(SIGINT, handle_sigint);
		signal(SIGQUIT, handle_sigquit);
		data->str = readline("💻 minishell > ");
		if (data->str == NULL)
		{
			// ici on fait ctrl+D,il ne faut pas oublier de free pour quitter proprement
			write(1, "exit\n", 5);
			exit(0);
		}
		if (ft_strlen(data->str) > 0)
		{
			add_history(data->str);
			if (ft_strcmp(data->str, "env") == 0)
				ft_env(data, cmd);
			if (parsing(data))
			{
				tmp = data->next;
				while (tmp)
				{
					if (tmp->type != WORD_S_QUOTES && ft_strchr(tmp->str, '$'))
					{
						expanded = expand_variables(tmp->str, envp);
						free(tmp->str);
						tmp->str = expanded;
					}
					printf("token type: %d, value: [%s]\n", tmp->type, tmp->str);
					printf("{%d -> %s}\n", tmp->type, tmp->str);
					tmp = tmp->next;
				}
			}
		}
		free(data->str);
	}
	free(data);
	return (0);
}
