/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:28:50 by amarouf           #+#    #+#             */
/*   Updated: 2024/04/03 00:29:31 by amarouf          ###   ########.fr       */
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

int	ft_index_count(t_list *val, int max)
{
	int	index;

	index = 0;
	while (val)
	{
		if (val->content < max)
			index++;
		val = val->next;
	}
	return (index);
}

void	ft_index(t_list *list)
{
	t_list	*val;
	t_list	*tmp;
	int		max;

	tmp = list;
	while (tmp)
	{
		max = INT_MAX;
		val = list;
		while (val)
		{
			if (val->content >= tmp->content && val->content < max)
				max = val->content;
			val = val->next;
		}
		tmp -> index = ft_index_count(list, max);
		tmp = tmp -> next;
	}
}
