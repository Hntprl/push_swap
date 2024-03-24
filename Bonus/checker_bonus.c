/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 05:33:48 by amarouf           #+#    #+#             */
/*   Updated: 2024/03/24 03:36:58 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void    ft_readmoves(t_list	**list_a)
{
	char    **str;
	int     i = 0;

	while (str[i])
	{
		str[i] = get_next_line(0);
		i ++;
	}
	   printf("%s\n", str[0]);
}

int main(int ac, char **av)
{
	
	if (ac > 2)
	{
		ft_check_chr(ac , av);
	}   
}