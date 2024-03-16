#include "push_swap.h"

void ft_check_chr(int ac, char **av)
{
	int		i;
	int		j;
	char	*str;
	char	*tmp;
	char	**num;

	i = 1;
	j = 0;
	str  = NULL;
	while (i < ac)
	{
		tmp = str;
		str = ft_strjoin(tmp, av[i ++]);
		free(tmp);
	}
	num = ft_split(str, ' ');
	if (!num[0])
	ft_check_ovf(num);
	ft_check_dbl(ac, av, str, num);
}

void ft_check_dbl(int ac, char **av, char *str, char **num)
{
	int i = 0;
	int j = 0;
	int *numbers;

	numbers = malloc(sizeof(int) * ft_wordcount(str, ' '));
	if (numbers == NULL)
		exit(1);
	i = 0;
	while (num[i])
	{
		numbers[i] = (int)ft_atoi(num[i]);
		i ++;
	}
	i = 0;
	while(i < ft_wordcount(str, ' '))
	{
	   j = i + 1;
		while(j < ft_wordcount(str, ' '))
		{
			if (numbers[j ++] == numbers[i])
				write(2, "Error!\n", 7), exit(1);
		}
		i ++;
	} 
}

void	ft_check_ovf(char **num)
{
	int i;

	i = 0;
	while (num[i])
	{
		if (ft_atoi(num[i]) > 2147483647 || ft_atoi(num[i]) < -2147483648)
			write(2, "Error!\n", 7), exit(1);
		i ++;
	}
}	