/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 04:42:02 by dtelnov           #+#    #+#             */
/*   Updated: 2022/07/19 16:43:19 by dtelnov          ###   ########.fr       */
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

void	last_digit(long long number, char *base)
{
	long long	k;

	k = number % ft_strlen(base);
	if (number != 0)
	{
		last_digit(number / ft_strlen(base), base);
		write(1, &base[k], 1);
	}
}

int	check_doublon(char *base, int caca)
{
	int	i;

	i = 0;
	while (base[i] < caca)
	{
		if (base[i] == caca)
			return (0);
		i++;
	}
	return (1);
}

int	check_base(char *base)
{
	int	i;

	i = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[i] != '\0')
	{
		if (check_doublon(base, i) == 0)
			return (0);
		if (base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long	number;

	if (check_base(base) == 0)
		return ;
	number = nbr;
	if (number == 0)
		write(1, &base[0], 1);
	else if (number < 0)
	{
		write(1, "-", 1);
		last_digit(-number, base);
	}
	else
		last_digit(number, base);
}

/*#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);

int		main(void)
{
	write(1, "42:", 3);
	ft_putnbr_base(-2147483648, "0123456789abcdef");
	write(1, "\n2a:", 4);
	ft_putnbr_base(42, "0123456789abcdef");
	write(1, "\n-2a:", 5);
	ft_putnbr_base(-42, "0123456789abcdef");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "0");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "+-0123456789abcdef");
	write(1, "17:", 2);
	ft_putnbr_base(42, "\t0123456789abcdef");
}*/
