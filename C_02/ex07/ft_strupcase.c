/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 05:32:12 by dtelnov           #+#    #+#             */
/*   Updated: 2022/07/10 21:34:09 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;
	int	lower;

	i = 0;
	lower = 0;
	if (str[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && 'z' >= str[i])
			lower = 1;
		if (lower)
			str[i] = str[i] - 32;
		lower = 0;
		i++;
	}
	return (str);
}
