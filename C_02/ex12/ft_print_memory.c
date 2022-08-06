/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:43:28 by dtelnov           #+#    #+#             */
/*   Updated: 2022/07/11 17:15:27 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define HEXVALUES "0123456789abcdef"

void	hex(unsigned char c)
{
	unsigned char	printed;

	printed = HEXVALUES[c / 16];
	write(1, &printed, 1);
	printed = HEXVALUES[c % 16];
	write(1, &printed, 1);
}

void	partie_gauche(void *addr)
{
	unsigned long	ull_addr;
	char			tab[16];
	int				i;

	ull_addr = (unsigned long) addr;
	i = 0;
	while (ull_addr > 0)
	{
		tab[i] = HEXVALUES[ull_addr % 16];
		ull_addr /= 16;
		i++;
	}
	while (i < 16)
	{
		tab[i] = '0';
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(1, &tab[i], 1);
		i--;
	}
	write(1, ": ", 2);
}

void	partie_milieu(void *addr, unsigned int size)
{
	unsigned char		*string_addr;
	unsigned int		i;
	unsigned int		k;

	string_addr = (unsigned char *) addr;
	i = 0;
	k = 0;
	while (i != 16)
	{
		if (size < 16 && i >= size)
		{
			write(1, "  ", 2);
			i++;
		}
		else
		{
			hex(string_addr[k]);
			i++;
			k++;
		}
		if (i % 2 == 0)
			write(1, " ", 1);
	}
}

void	partie_droite(void *addr, unsigned int size)
{
	unsigned char				*string_addr;
	unsigned int				i;
	unsigned int				k;

	string_addr = (unsigned char *) addr;
	i = 0;
	k = 0;
	while (i != size)
	{
		if (string_addr[k] > 31 && 127 > string_addr[k])
			write(1, &string_addr[k], 1);
		else
			write(1, ".", 1);
		k++;
		i++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (size - i >= 16)
		{
			partie_gauche(addr + i);
			partie_milieu(addr + i, 16);
			partie_droite(addr + i, 16);
		}
		else
		{
			partie_gauche(addr + i);
			partie_milieu(addr + i, size - i);
			partie_droite(addr + i, size - i);
		}
		i += 16;
	}
	return (addr);
}
