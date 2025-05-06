/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:43:07 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/05/06 19:55:51 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void token_append(t_struct *data)
{
    int i;
    
    if (!data || !data->str)
        return;
    
    i = 0;
    while(data->str[i])
    {
        // Cas ">>"
        if(data->str[i] == '>' && data->str[i + 1] == '>')
        {
            i++;
            while(data->str[i] && data->str[i] == ' ')
                i++;
            if(data->next)
            {
                data->type = HEREDOC;
                data->next->type = WORD;
                
                printf("Type du token actuel: %d\n", data->type);
                printf("Type du token suivant: %d\n", data->next->type);
            }
        }
        // Cas ">"
        else if(data->str[i] == '>')
        {
            i++;
            while(data->str[i] && data->str[i] == ' ')
                i++;
            if(data->next)
            {
                data->type = REDIR_IN;
                data->next->type = WORD;
                
                printf("Type du token actuel: %d\n", data->type);
                printf("Type du token suivant: %d\n", data->next->type);
            }
        }
        // Cas "<"
        else if(data->str[i] == '<')
        {
            i++;
            while(data->str[i] && data->str[i] == ' ')
                i++;
            if(data->next)
            {
                data->type = REDIR_OUT;
                data->next->type = WORD;
                
                printf("Type du token actuel: %d\n", data->type);
                printf("Type du token suivant: %d\n", data->next->type);
            }
        }
        // Cas "<<"
        else if(data->str[i] == '<' && data->str[i + 1] == '<')
        {
            i++;
            while(data->str[i] && data->str[i] == ' ')
                i++;
            if(data->next)
            {
                data->type = HEREDOC;
                data->next->type = WORD;
                
                printf("Type du token actuel: %d\n", data->type);
                printf("Type du token suivant: %d\n", data->next->type);
            }
        }
        i++;
    }
    printf("État final - Type token courant: %d\n", data->type);
    if(data->next)
        printf("État final - Type token suivant: %d\n", data->next->type);
}
