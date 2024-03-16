//   int i = 1;
//     int j;

//     while (i < ac)
//     {
//         j = 0;
//         while (av[i][j] != '\0')
//         {
//             while (av[i][j] == ' ')
//                 j ++;  
//             if (av[i][j] < '0' || av[i][j] > '9')
//                 exit(write(2, "Error\n", 6));
//             j ++;
//         }
//         i ++;
//     }
//     write (1, "OK", 2);
#include "push_swap.h"

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		i ++;
// 	}
// 	return (i);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*p;

// 	i = 0;
// 	j = 0;
// 	if (s1 == NULL || s2 == NULL)
// 		return (NULL);
// 	p = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 2 * sizeof(char));
// 	if (p == NULL)
// 		return (NULL);
// 	while (s1[i] != '\0')
// 	{
// 		p[i] = s1[i];
// 		i ++;
// 	}
// 	p[i] = ' ';
// 	i ++;
// 	while (s2[j] != '\0')
// 	{
// 		p[i + j] = s2[j];
// 		j ++;
// 	}
// 	p[i + j] = '\0';
// 	return (p);
// }

// int main (int ac, char **av)
// {
// 	int i = ft_atoi(av[1]);
// 	printf("%d", i);
// }

int main (int ac, char **av)
{
	printf("%d\n", INT_MAX);
	printf("%d", INT_MIN);
}