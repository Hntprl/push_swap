/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:15:33 by amarouf           #+#    #+#             */
/*   Updated: 2024/03/19 20:58:42 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fill_list(int *numbers, int size)
{
	t_list *list_a;
	int i;

	list_a = malloc(sizeof(t_list));
	if (list_a == NULL)
		exit(1);
	list_a->content = numbers[0];
	list_a->next = NULL;
	i = 1;
	while (i < size - 1)
		ft_lstadd_back(&list_a, ft_lstnew(numbers[i ++]));
	free(numbers);
	ft_sorted_numbers(list_a);
	if (ft_lstsize(list_a) == 3)
		ft_three(list_a, 'a');
	if (ft_lstsize(list_a) == 4)
		ft_four(list_a);
	if (ft_lstsize(list_a) == 5)
		ft_five (list_a);
	ft_lstclear(&list_a, del);
}

int main (int ac, char **av)
{
	if (ac < 2)
		(exit(0));
	ft_check_chr(ac, av);
	return 0;
}