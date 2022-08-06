/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base-1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 10:55:52 by dtelnov           #+#    #+#             */
/*   Updated: 2022/07/26 11:07:54 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	convertisseur_fou(char a, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (a == base[i])
			return (i);
		i++;
	}
	return (0);
}

int	dedansbase(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}

int	samelook(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+' || str[i] > 126 || str[i] < 32)
			return (1);
		while (str[j])
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int			n;
	long int	result;

	result = 0;
	n = 1;
	if (ft_strlen(base) <= 1)
		return (0);
	if (samelook(base) == 1)
		return (0);
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	while (*str == 45 || *str == 43)
	{
		if (*str == 45)
			n = n * -1;
		str++;
	}
	while (dedansbase(*str, base) == 1)
	{
		result = (result * ft_strlen(base)) + convertisseur_fou(*str, base);
		str++;
	}
	result = result * n;
	return (result);
}
