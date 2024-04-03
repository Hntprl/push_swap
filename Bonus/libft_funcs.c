/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:47:23 by amarouf           #+#    #+#             */
/*   Updated: 2024/04/03 02:52:54 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i ++;
	}
	return (i);
}

long	ft_atoi(char *str)
{
	long	sign;
	long	i;
	long	sum;

	i = 0;
	sign = 1;
	sum = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i])
	{
		sum *= 10;
		sum += str[i] - '0';
		i++;
	}
	return (sum * sign);
}

int	ft_check_space(char *s1, char *s2)
{
	int	s;

	s = 0;
	if (s1[0] == '\0' || s2[0] == '\0')
		return (1);
	while (s2[s] == ' ')
	{
		if (s2[s + 1] == '\0')
			return (1);
		s ++;
	}
	s = 0;
	while (s1[s] == ' ')
	{
		if (s1[s + 1] == '\0')
			return (1);
		s ++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*p;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	p = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
	if (p == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i ++;
	}
	while (s2[j] != '\0')
	{
		p[i + j] = s2[j];
		j ++;
	}
	p[i + j] = '\0';
	return (p);
}

char	*ft_strjoin_chr(char *s1, char *s2)
{
	char	*all;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2[0])
		return (NULL);
	if (ft_check_space(s1, s2) == 1)
		return (NULL);
	all = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!all)
		return (NULL);
	while (s1[++i])
		all[j++] = s1[i];
	all[j ++] = ' ';
	i = -1;
	while (s2[++i])
		all[j++] = s2[i];
	all[j] = 0;
	return (all);
}
