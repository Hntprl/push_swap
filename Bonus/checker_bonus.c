/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 05:33:48 by amarouf           #+#    #+#             */
/*   Updated: 2024/03/22 19:47:01 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void    ft_readmoves()
{
    char    *str;
    int     i = 0;

    while (str)
    {
        str = get_next_line(0);
         printf("%s", str);
    }
        
   
}

int main(int ac, char **av)
{
    
    if (ac > 2)
    {
        ft_readmoves();
    }   
}