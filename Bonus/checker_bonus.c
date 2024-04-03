/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 05:33:48 by amarouf           #+#    #+#             */
/*   Updated: 2024/04/03 05:33:09 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_fill_list(int *numbers, int size)
{
	t_list	*list_a;
	t_list	*list_b;
	int		i;

	list_b = NULL;
	list_a = malloc(sizeof(t_list));
	if (list_a == NULL)
		(write(2, "Error\n", 6), exit(1));
	list_a->content = numbers[0];
	list_a->next = NULL;
	i = 1;
	while (i < size - 1)
		ft_lstadd_back(&list_a, ft_lstnew(numbers[i ++]));
	free(numbers);
	ft_readmoves(list_a);
	ft_lstclear(&list_a, del);
}

void	ft_readmoves(t_list	*list_a)
{
	char	*str;
	t_list	*list_b;

	list_b = NULL;
	str = get_next_line(0);
	while (str)
	{
		ft_sort_list(str, &list_a, &list_b);
		free(str);
		str = get_next_line(0);
	}
	if (list_b)
	{
		if (list_a)
			ft_lstclear(&list_a, del);
		(ft_lstclear(&list_b, del), write(2, "KO\n", 3), exit(1));
	}
	ft_sorted_numbers(list_a);
}

void	ft_sort_list(char *moves, t_list **list_a, t_list **list_b)
{
	if (ft_strnstr(moves, "sa\n", 3))
		ft_swap(list_a);
	else if (ft_strnstr(moves, "sb\n", 3))
		ft_swap(list_b);
	else if (ft_strnstr(moves, "pa\n", 3))
		ft_push(list_b, list_a);
	else if (ft_strnstr(moves, "pb\n", 3))
		ft_push(list_a, list_b);
	else if (ft_strnstr(moves, "ra\n", 3))
		ft_rotate(list_a);
	else if (ft_strnstr(moves, "rb\n", 3))
		ft_rotate(list_b);
	else if (ft_strnstr(moves, "rra\n", 4))
		ft_r_rotate(list_a);
	else if (ft_strnstr(moves, "rrb\n", 4))
		ft_r_rotate(list_b);
	else if (ft_strnstr(moves, "rr\n", 3))
		ft_rotate_rotate(list_a, list_b);
	else if (ft_strnstr(moves, "ss\n", 3))
		(ft_swap(list_b), ft_swap(list_a));
	else if (ft_strnstr(moves, "rrr\n", 4))
		(ft_r_rotate(list_b), ft_r_rotate(list_a));
	else
		ft_sort_list_v(moves, list_a, list_a);
}

void	ft_sort_list_v(char *moves, t_list **list_a, t_list **list_b)
{
	if (list_b)
		ft_lstclear(list_b, del);
	(ft_lstclear(list_a, del), free(moves), write(2, "Error\n", 6), exit(1));
}

int	main(int ac, char **av)
{
	if (ac > 1)
		ft_make_str(ac, av);
	return (0);
}
