/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 05:33:48 by amarouf           #+#    #+#             */
/*   Updated: 2024/03/27 02:47:55 by amarouf          ###   ########.fr       */
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
		exit(1);
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
		(write(2, "OK\n", 3), exit(1));
	ft_sorted_numbers(list_a);
}

void	ft_sort_list(char *moves, t_list **list_a, t_list **list_b)
{
	if (ft_strnstr(moves, "sa", 2))
		(write(1, "sa\n", 3), ft_swap(list_a));
	else if (ft_strnstr(moves, "sb", 2))
		(write(1, "sb\n", 3), ft_swap(list_b));
	else if (ft_strnstr(moves, "pa", 2))
		(write(1, "pa\n", 3), ft_push(list_b, list_a));
	else if (ft_strnstr(moves, "pb", 2))
		(write(1, "pb\n", 3), ft_push(list_a, list_b));
	else if (ft_strnstr(moves, "ra", 2))
		(write(1, "ra\n", 3), ft_rotate(list_a));
	else if (ft_strnstr(moves, "rb", 2))
		(write(1, "rb\n", 3), ft_rotate(list_b));
	else if (ft_strnstr(moves, "rra", 3))
		(write(1, "rra\n", 4), ft_r_rotate(list_a));
	else if (ft_strnstr(moves, "rrb", 3))
		(write(1, "rrb\n", 4), ft_r_rotate(list_b));
	else if (ft_strnstr(moves, "rr", 2))
		(write(1, "rr\n", 3), ft_rotate_rotate(list_a, list_b));
	else if (ft_strnstr(moves, "ss", 2))
		(write(1, "ss\n", 3), ft_swap(list_b), ft_swap(list_a));
	else if (ft_strnstr(moves, "rrr", 3))
		((write(1, "rrr\n", 4), ft_r_rotate(list_b), ft_r_rotate(list_a)));
	else
		(write(2, "Error\n", 6), exit(1));
}

int	main(int ac, char **av)
{
	if (ac > 1)
		ft_check_chr(ac, av);
	return (0);
}
