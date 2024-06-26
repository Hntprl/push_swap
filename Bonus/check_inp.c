/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 05:10:57 by amarouf           #+#    #+#             */
/*   Updated: 2024/04/03 02:58:33 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_make_str(int ac, char **av)
{
	int		i;
	char	*str;
	char	*tmp;
	char	**num;

	i = 1;
	str = NULL;
	while (i < ac)
	{
		tmp = str;
		str = ft_strjoin_chr(tmp, av[i ++]);
		if (str == NULL)
			(free(tmp), write(2, "Error\n", 6), exit(1));
		free(tmp);
	}
	num = ft_split(str, ' ');
	if (!num[0])
		(free_strings(num), free(str), write(2, "Error\n", 6), exit(1));
	ft_check_ovf(num, str);
	ft_check_dbl(str, num);
}

int	ft_check_char(char *num)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (num[i])
	{
		if ((num[i] > '0' || num[i] < '9')
			&& (num[i + 1] == '+' || (num[i + 1] == '-')))
			return (1);
		if (num[i] == '-' || num[i] == '+')
			i ++;
		if (num[i] < '0' || num[i] > '9')
			return (1);
		i ++;
	}
	return (0);
}

int	*ft_numbers(char **num, int size)
{
	int	i;
	int	*numbers;

	i = 0;
	numbers = malloc(sizeof(int) * (size - 1));
	if (numbers == NULL)
		exit(1);
	while (num[i])
	{
		if (ft_check_char(num[i]) == 1)
			(free(numbers), free_strings(num), write(2, "Error\n", 6), exit(1));
		numbers[i] = (int)ft_atoi(num[i]);
		i ++;
	}
	free_strings(num);
	return (numbers);
}

void	ft_check_dbl(char *str, char **num)
{
	int	i;
	int	j;
	int	size;
	int	*numbers;

	i = 0;
	j = 0;
	size = count_words(str, ' ');
	free(str);
	numbers = ft_numbers(num, size);
	while (i < (size - 1))
	{
		j = i + 1;
		while (j < (size - 1))
		{
			if (numbers[j] == numbers[i])
				(free(numbers), write(2, "Error\n", 6), exit(1));
			j ++;
		}
		i ++;
	}
	ft_fill_list(numbers, size);
}

void	ft_check_ovf(char **num, char *str)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (ft_atoi(num[i]) > 2147483647 || ft_atoi(num[i]) < -2147483648)
			(free(str), free_strings(num), write(2, "Error\n", 6), exit(1));
		i ++;
	}
}
