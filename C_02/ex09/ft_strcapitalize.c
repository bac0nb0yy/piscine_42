/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 09:41:46 by dtelnov           #+#    #+#             */
/*   Updated: 2022/07/09 16:51:26 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;
	int	upper;

	i = 0;
	upper = 0;
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

int	ft_char_is_alpha(char c)
{
	return ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'));
}

void	truc(char *c, int *x)
{
	*c -= 32;
	*x = 0;
}

int	ft_char_is_numeric(char c)
{
	return ((c <= 57 && c >= 48));
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	debut_mot;

	i = 0;
	debut_mot = 1;
	str = ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if (ft_char_is_alpha(str[i]) && debut_mot)
			truc(&str[i], &debut_mot);
		else if (ft_char_is_numeric(str[i]))
			debut_mot = 0;
		else if (ft_char_is_alpha(str[i]) && !(ft_char_is_alpha(str[i - 1])))
		{
			if (!ft_char_is_numeric(str[i - 1]))
				truc(&str[i], &debut_mot);
		}
		i++;
	}
	return (str);
}
