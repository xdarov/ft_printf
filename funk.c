/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorina <pcorina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:37:36 by pcorina           #+#    #+#             */
/*   Updated: 2021/10/27 11:09:41 by pcorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_revers(char *str)
{
	char			ch;
	unsigned int	i;
	unsigned int	j;

	j = (unsigned int)ft_strlen(str) - 1;
	i = 0;
	while (i < j)
	{
		ch = str[i];
		str[i] = str[j];
		str[j] = ch;
		i++;
		j--;
	}
	write(1, str, ft_strlen(str));
}

void	ft_hexadecimal(unsigned long long num, int *result, char a)
{
	char	str[20];
	int		i;

	i = 0;
	while (num >= 16)
	{
		if (num % 16 >= 10)
			str[i] = num % 16 - 10 + a;
		else
			str[i] = num % 16 + '0';
		i++;
		num = num / 16;
	}
	if (num >= 10)
		str[i++] = num - 10 + a;
	else
		str[i++] = num + '0';
	str[i] = '\0';
	*result += ft_strlen(str);
	ft_revers(str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
