/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:23:24 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/05/05 22:14:29 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv)
{
	t_struct	*data;

	(void)argv;
	data = (t_struct *)malloc(sizeof(t_struct));
	if (!data)
	{
		perror("Error allocating memory");
		return (1);
	}
	if (argc != 1)
	{
		printf("Error : need only one arguments\n");
		return (0);
	}
	else
	{
		while (1)
		{
			data->str = readline("💻 minishell > ");
			parsing(data);
			if (data->str == NULL)
				break ;
			if (ft_strlen(data->str) > 0)
			{
				add_history(data->str);
				free(data->str);
			}
		}
	}
	free(data);
	return (0);
}
