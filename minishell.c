/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:23:24 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/05/02 17:00:27 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv)
{
    (void)argv;
    char *input;
    input = NULL;

    if(argc != 1)
    {
        printf("Error : need only one arguments\n");
        return(0);
    }
    else
    {
        while(1)
        {
            input = readline("💻🔞 minishell > ");
            if(input == NULL)
                break;
            if (ft_strlen(input) > 0)
            {
                add_history(input);
                free(input);
            }
        }
    }
    return(0);
}