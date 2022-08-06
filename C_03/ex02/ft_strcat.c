/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 22:29:33 by dtelnov           #+#    #+#             */
/*   Updated: 2022/07/15 00:03:09 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *dest)
{
	int	i;

	i = 0;
	if (dest[i] == '\0')
		return (0);
	while (dest[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	dest_src;

	dest_src = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[dest_src + i] = src[i];
		i++;
	}
	dest[dest_src + i] = '\0';
	return (dest);
}
