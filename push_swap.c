/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:15:33 by amarouf           #+#    #+#             */
/*   Updated: 2024/03/15 17:55:19 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int ac, char **av)
{
    int i = 1;
    char *str;
    char *tmp;

    str  = NULL;
    while (i < ac)
    {
        tmp = str;
        str = ft_strjoin(tmp, av[i ++]);
        free(tmp);
    }
    printf ("%s", str);
}
