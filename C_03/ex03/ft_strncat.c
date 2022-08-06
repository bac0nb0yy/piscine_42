/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:43:11 by dtelnov           #+#    #+#             */
/*   Updated: 2022/07/13 04:19:16 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *dest)
{
	unsigned int	i;

	i = 0;
	if (dest[i] == '\0')
		return (0);
	while (dest[i] != '\0')
		i++;
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	dest_src;

	dest_src = ft_strlen(dest);
	i = 0;
	while (i < nb && src[i] != '\0')
	{
		dest[dest_src + i] = src[i];
		i++;
	}
	dest[dest_src + i] = '\0';
	return (dest);
}
