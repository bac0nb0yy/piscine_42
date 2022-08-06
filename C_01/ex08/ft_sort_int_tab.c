/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:49:16 by dtelnov           #+#    #+#             */
/*   Updated: 2022/07/07 16:22:53 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	k;
	int	tmp;	

	i = 0;
	while (i < size)
	{
		k = 0;
		while (k < size - 1)
		{
			if (tab[k] > tab[k + 1])
			{
				tmp = tab[k + 1];
				tab[k + 1] = tab[k];
				tab[k] = tmp;
			}
			k++;
		}
		i++;
	}
}
