/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:03:06 by dtelnov           #+#    #+#             */
/*   Updated: 2022/07/13 04:18:14 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	k;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		k = 0;
		if (str[i] == to_find[k])
		{
			while (str[i + k] == to_find[k])
			{
				k++;
				if (to_find[k] == '\0')
					return (&str[i]);
			}
		}
		i++;
	}
	return (0);
}
