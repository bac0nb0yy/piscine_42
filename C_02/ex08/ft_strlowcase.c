/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 05:32:12 by dtelnov           #+#    #+#             */
/*   Updated: 2022/07/10 21:34:59 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;
	int	upper;

	i = 0;
	upper = 0;
	if (str[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && 'Z' >= str[i])
			upper = 1;
		if (upper)
			str[i] = str[i] + 32;
		upper = 0;
		i++;
	}
	return (str);
}
