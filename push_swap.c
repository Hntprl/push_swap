/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:15:33 by amarouf           #+#    #+#             */
/*   Updated: 2024/03/16 17:28:52 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_fill_list(int *numbers, int size)
{
    t_list *list;
    int i;
    
    list = malloc(sizeof(t_list));
    if (list == NULL)
        return (NULL);
    list->content = numbers[0];
    list->next = NULL;
    i = 1;
    while (i < size - 1)
    {
        ft_lstadd_back(&list, ft_lstnew(numbers[i]));
        i++;
    }
    ft_swap(&list);
    while (list)
    {
        printf("%d\n", list->content);
        list = list->next;
    }
    return (list);
}

int main (int ac, char **av)
{
    if (ac < 2)
        (exit(0));
    ft_check_chr(ac, av);
    write(2, "OK!", 3);
    return 0;
}