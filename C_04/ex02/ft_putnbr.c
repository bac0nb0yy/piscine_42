/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:23:45 by dtelnov           #+#    #+#             */
/*   Updated: 2022/07/12 12:27:30 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_number(int number)
{
	ft_putchar('0' + number);
}

void	last_digit(int number)
{
	int	k;

	k = number % 10;
	if (number != 0)
	{
		last_digit(number / 10);
		print_number(k);
	}
}

void	ft_putnbr(int nb)
{
	if (nb == 0)
	{
		write(1, "0", 1);
	}
	else if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		last_digit(-nb);
	}
	else
	{
		last_digit(nb);
	}
}
