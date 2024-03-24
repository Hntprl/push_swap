/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:50:31 by amarouf           #+#    #+#             */
/*   Updated: 2024/03/24 06:04:14 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_fill_list(int *numbers, int size)
{
	t_list *list_a;
	t_list *list_b;
	int i;

    list_b = NULL;
	list_a = malloc(sizeof(t_list));
	if (list_a == NULL)
		exit(1);
	list_a->content = numbers[0];
	list_a->next = NULL;
	i = 1;
	while (i < size - 1)
		ft_lstadd_back(&list_a, ft_lstnew(numbers[i ++]));
	free(numbers);
	ft_readmoves(&list_a);
}

void	(t_list *list_a)
{
	char **moves;

	moves = ft_readmoves();
}