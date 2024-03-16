/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opirations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 05:11:10 by amarouf           #+#    #+#             */
/*   Updated: 2024/03/16 17:32:30 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap(t_list **list)
{
    t_list *tmp;

    tmp = (*list)->next;
    (*list)->next = tmp->next;
    tmp->next = (*list);
    (*list) = tmp;
}

void ft_push(t_list **list)
{
   t_list *tmp;
}