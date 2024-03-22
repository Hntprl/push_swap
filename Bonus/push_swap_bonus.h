/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 05:35:46 by amarouf           #+#    #+#             */
/*   Updated: 2024/03/22 19:53:46 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
#define PUSH_SWAP_BONUS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  111111
# endif

//libft
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);

//check_inp
void    ft_check_chr(int ac, char **av);
int     ft_check_def(char *num);
int     *ft_numbers(char **num, int size);
void    ft_check_dbl(int ac, char **av, char *str, char **num);
void    ft_check_ovf(char **num, char *str);
void	ft_fill_list(int *numbers, int size);
#endif