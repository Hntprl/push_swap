/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:47:23 by amarouf           #+#    #+#             */
/*   Updated: 2024/03/24 02:43:38 by amarouf          ###   ########.fr       */
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

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*k;
	char	ch;

	ch = c;
	i = 0;
	k = (char *)s;
	while (k[i] != '\0')
	{
		if (k[i] == ch)
			return (k + i);
		i++;
	}
	if (ch == '\0')
		return (k + i);
	return (NULL);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
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