/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:52:13 by dtelnov           #+#    #+#             */
/*   Updated: 2022/07/15 11:36:59 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0' || s2[i] != '\0'))
			i++;
	if (s1[i] == s2[i])
		return (0);
	else if (s1[i] > s2[i])
		return (1);
	else
		return (-1);
}

void	putstrr(int i, int ac, char **av)
{
	while (i < ac)
	{
		putstr(av[i]);
		write(1, "\n", 1);
		i++;
	}
}	

int	main(int ac, char **av)
{
	int		i;
	int		k;
	char	*tmp;

	i = 0;
	while (i < ac)
	{
		k = 1;
		while (k < (ac - 1 - i))
		{
			if (ft_strcmp(av[k], av[k + 1]) > 0)
			{
				tmp = av[k];
				av[k] = av[k + 1];
				av[k + 1] = tmp;
			}
			k++;
		}
		i++;
	}
	putstrr(1, ac, av);
}
