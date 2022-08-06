/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:33:59 by dtelnov           #+#    #+#             */
/*   Updated: 2022/07/13 03:14:15 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	space_len(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			i++;
	}
	return (i);
}

int	is_neg(char *str, int space)
{
	int	i;
	int	compteur;

	compteur = 0;
	i = 0;
	if (str[space + i] == '+' || str[space + i] == '-')
	{
		while (str[space + i] == '+' || str[space + i] == '-')
		{
			if (str[space + i] == '-')
				compteur++;
			i++;
		}
	}
	return (compteur % 2);
}

int	apres_signe(char *str, int space)
{
	int	i;

	i = 0;
	if (str[space + i] == '+' || str[space + i] == '-')
	{
		while (str[space + i] == '+' || str[space + i] == '-')
			i++;
	}
	return (space + i);
}

int	ft_atoi(char *str)
{
	int	result;
	int	i;
	int	neg;
	int	apress;

	i = 0;
	result = 0;
	neg = is_neg(str, space_len(str));
	apress = apres_signe(str, space_len(str));
	while (str[apress + i] >= '0' && str[apress + i] <= '9')
	{
		result = result * 10 + str[apress + i] - '0';
		i++;
	}
	if (neg)
		return (-result);
	return (result);
}
