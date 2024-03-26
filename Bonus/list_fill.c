/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:50:31 by amarouf           #+#    #+#             */
/*   Updated: 2024/03/25 21:30:05 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_sorted_numbers(t_list *list_a)
{
	t_list	*tmp;

	tmp = list_a;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			write(1, "KO\n", 3), exit(0);
		tmp = tmp->next;
	}
	ft_lstclear(&list_a, del);
	write(1, "OK\n", 3), exit(0);
}