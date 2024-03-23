/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:28:50 by amarouf           #+#    #+#             */
/*   Updated: 2024/03/23 20:19:24 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_highnum(t_list *list)
{
	t_list	*tmp;
	t_list	*max;

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
	t_list	*tmp;
	t_list	*min;

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

int	ft_posmid(t_list *list_b)
{
	int	i;

	i = 0;
	while (list_b)
	{
		if (list_b == ft_highnum(list_b))
			return (i);
		list_b = list_b->next;
		i++;
	}
	return (i);
}

int	ft_index_count(t_list *val, int min)
{
	int	index;

	index = 0;
	while (val)
	{
		if (val->content < min)
			index++;
		val = val->next;
	}
	return (index);
}

void	ft_index(t_list *list)
{
	t_list	*val;
	t_list	*tmp;
	int		min;

	tmp = list;
	while (tmp)
	{
		min = INT_MAX;
		val = list;
		while (val)
		{
			if (val->content >= tmp->content && val->content < min)
				min = val->content;
			val = val->next;
		}
		val = list;
		tmp -> index = ft_index_count(val, min);
		tmp = tmp -> next;
	}
}
