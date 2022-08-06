/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:43:28 by dtelnov           #+#    #+#             */
/*   Updated: 2022/07/11 17:15:27 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define HEXVALS "0123456789abcdef"

void	hex(unsigned char c)
{
	unsigned char	printed;

	printed = HEXVALS[c / 16];
	write(1, &printed, 1);
	printed = HEXVALS[c % 16];
	write(1, &printed, 1);
}

int	ft_char_is_not_printable(unsigned char c)
{
	return ((31 >= c) || (c >= 127));
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_char_is_not_printable(str[i]))
		{
			write(1, "\\", 1);
			hex(str[i]);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			i++;
		}
	}
}
