/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:15:37 by amarouf           #+#    #+#             */
/*   Updated: 2024/03/16 02:04:03 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

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

#endif