/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:15:33 by amarouf           #+#    #+#             */
/*   Updated: 2024/03/18 01:09:19 by amarouf          ###   ########.fr       */
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

void check_operations(t_list *list)
{
	t_list *tmp;
	t_list *max;

	tmp = list;
	max = ft_highnum(tmp);
	if (max == list)
		ft_rotate(&list);
	if (max->content == list->next->content)
		ft_reverse_rotate(&list);
	if (max->content == list->next->next->content)
	{
		if (list->content > list->next->content)
			ft_swap(&list);
	}
}

void	ft_fill_list(int *numbers, int size)
{
	t_list *list;
	int i;
	
	list = malloc(sizeof(t_list));
	if (list == NULL)
		return ;
	list->content = numbers[0];
	list->next = NULL;
	i = 1;
	while (i < size - 1)
	{
		ft_lstadd_back(&list, ft_lstnew(numbers[i]));
		i++;
	}
	if (ft_lstsize(list) == 3)
		check_operations(list);
}

int main (int ac, char **av)
{
	if (ac < 2)
		(exit(0));
	ft_check_chr(ac, av);
	write(2, "OK!", 3);
	return 0;
}