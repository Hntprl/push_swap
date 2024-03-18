/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:15:37 by amarouf           #+#    #+#             */
/*   Updated: 2024/03/18 07:02:08 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_list
{
    int				content;
    struct s_list	*next;
}   t_list;

//Libft
long     ft_atoi(char *str);
char	*ft_strrchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
int     count_words(char const *str, char c);
void	free_strings(char **strings);

//Check_input
void    ft_check_dbl(int ac, char **av, char *str, char **num);
void    ft_check_chr(int ac, char **av);
void	ft_check_ovf(char **num);
void    ft_fill_list(int *numbers, int size);
t_list	*ft_highnum(t_list *list);
void    ft_three(t_list *list, char stack);
void	ft_four(t_list *list_a);
void	ft_five (t_list *list_a);

//List
t_list	*ft_lstnew(int  content);
void	ft_lstadd_back(t_list **list, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int     ft_lstsize(t_list *lst);

//Actions
void ft_swap(t_list **list, char stack);
void ft_push(t_list **list, t_list **list2, char stack);
void ft_rotate(t_list **list, char stack);
void ft_reverse_rotate(t_list **list, char stack);

//Free
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void    del(void *lst);

#endif