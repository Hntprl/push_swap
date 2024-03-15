/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:47:23 by amarouf           #+#    #+#             */
/*   Updated: 2024/03/15 17:53:18 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_atoi(const char *str)
{
	int	i;
	int	s;
	int	a;

	s = 1;
	i = 0;
	a = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
	{
		i ++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			s *= -1;
		}
		i ++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		a = (str[i] - '0') + (a * 10);
		i ++;
	}
	return (a * s);
}

char	*ft_strjoin(char *s1, char *s2)
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
	if (!s2)
		return (ft_strdup(s1));
	all = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!all)
		return (NULL);
	while (s1[++i])
		all[j++] = s1[i];
	all[j] = ' ';
	j++;
	i = -1;
	while (s2[++i])
		all[j++] = s2[i];
	all[j] = 0;
	return (all);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (c == '\0')
	{
		return ((char *)s + i);
	}
	while (i >= 0)
	{
		if (s[i] == (char)c)
		{
			return ((char *)s + i);
		}
		i --;
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*p;

	i = 0;
	p = (char *) malloc(ft_strlen(s1) + 1 * sizeof(char));
	if (p == NULL)
	{
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i ++;
	}
	p[i] = '\0';
	return (p);
}
