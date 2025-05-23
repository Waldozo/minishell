/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:23:24 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/05/23 20:53:37 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv)
{
	t_struct	*data;
	t_struct	*tmp;

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
	while (1)
	{
		data->str = readline("💻 minishell > ");
		if (data->str == NULL)
			break ;
		if (ft_strlen(data->str) > 0)
		{
			add_history(data->str);
			if (parsing(data))
			{
				tmp = data->next;
				while (tmp)
				{
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
