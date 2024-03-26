/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 05:33:48 by amarouf           #+#    #+#             */
/*   Updated: 2024/03/25 23:26:05 by amarouf          ###   ########.fr       */
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
	ft_readmoves(list_a);
	ft_lstclear(&list_a, del);
}

void    ft_readmoves(t_list	*list_a)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		ft_sort_list(str, &list_a);
		free(str);
		str = get_next_line(0);	
	}
	printf("%d\n", list_a->content);
	ft_sorted_numbers(list_a);
}

void	ft_sort_list(char *moves, t_list **list_a)
{
	t_list	*list_b;
	int	i;

	i = 0;
	list_b = NULL;
		if (ft_strnstr(moves, "sa", 2))
			ft_swap(list_a);
		
		else if (ft_strnstr(moves, "sb", 2))
			ft_swap(&list_b);
		else if (ft_strnstr(moves, "pa", 2))
			ft_push(&list_b, list_a);
		else if (ft_strnstr(moves, "pb", 2))
			ft_push(list_a, &list_b);
		else if (ft_strnstr(moves, "ra", 2))
			ft_rotate(list_a);
		else if (ft_strnstr(moves, "rb", 2))
			ft_rotate(&list_b);
		else if (ft_strnstr(moves, "rra", 3))
			ft_reverse_rotate(list_a);
		else if (ft_strnstr(moves, "rrb", 3))
			ft_reverse_rotate(list_a);
		else if (ft_strnstr(moves, "rr", 2))
			ft_rotate_rotate(list_a, &list_b);
		else if (ft_strnstr(moves, "ss", 2))
			ft_swap(&list_b),ft_swap(list_a);
		else if (ft_strnstr(moves, "rrr", 3))
			(ft_reverse_rotate(&list_b), ft_reverse_rotate(list_a));
		else
			(write(2, "Error\n", 6), exit(1));
		
}

int main(int ac, char **av)
{
	
	if (ac > 2)
	{
		ft_check_chr(ac , av);
	}
	return (0);
}