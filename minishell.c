/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:23:24 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/05/06 18:29:01 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **env)
{
    t_struct    *data;
    char        *path;
    char        **paths;

    (void)argv;
    if (argc != 1)
    {
        printf("Error: need only one argument\n");
        return (1);
    }
    path = getenv("PATH");
    if (path == NULL)
    {
        printf("Error: PATH environment variable not set\n");
        return (1);
    }
    paths = ft_split(path, ':');
    if (!paths)
    {
        printf("Error: failed to split PATH\n");
        return (1);
    }
    data = (t_struct *)malloc(sizeof(t_struct));
    if (!data)
    {
        perror("Error allocating memory");
        free_paths(paths);
        return (1);
    }
    data->env = env;
    data->paths = paths;
    while (1)
    {
        data->str = readline("💻 minishell > ");
        if (data->str == NULL)
            break;
            
        if (ft_strlen(data->str) > 0)
        {
            add_history(data->str);
            parsing(data);
        }
        free(data->str);
    }
    free_paths(paths);
    free(data);
    return (0);
}
