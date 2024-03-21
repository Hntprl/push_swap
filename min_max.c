/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:28:50 by amarouf           #+#    #+#             */
/*   Updated: 2024/03/18 22:29:23 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_highnum(t_list *list)
{
	t_list *tmp;
	t_list *max;

	tmp = list;
	max = tmp;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->content > max->content)
			max = tmp;
	}
	return (max);
}

t_list	*ft_minnum(t_list *list)
{
	t_list *tmp;
	t_list *min;

	tmp = list;
	min = tmp;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->content < min->content)
			min = tmp;
	}
	return (min);
}