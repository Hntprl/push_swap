/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 05:35:46 by amarouf           #+#    #+#             */
/*   Updated: 2024/03/27 02:47:08 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  111111
# endif

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}		t_list;

//libft
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
int		count_words(char const *str, char c);
void	free_strings(char **strings);
long	ft_atoi(char *str);
char	*ft_strjoin_chr(char *s1, char *s2);
int		ft_check_space(char *s1, char *s2);

//check_inp
void	ft_check_chr(int ac, char **av);
int		ft_check_def(char *num);
int		*ft_numbers(char **num, int size);
void	ft_check_dbl(char *str, char **num);
void	ft_check_ovf(char **num, char *str);
void	ft_fill_list(int *numbers, int size);
void	ft_readmoves(t_list	*list_a);
void	ft_sorted_numbers(t_list *list_a);
void	ft_sort_list(char *moves, t_list **list_a, t_list **list_b);

//List
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	del(void *lst);
void	ft_lstclear(t_list **lst, void (*del)(void *));
int		ft_lstsize(t_list *lst);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

//Opirations
void	ft_swap(t_list **list);
void	ft_push(t_list **list, t_list **list2);
void	ft_rotate(t_list **list);
void	ft_r_rotate(t_list **list);
void	ft_rotate_rotate(t_list	**list_a, t_list **list_b);
#endif