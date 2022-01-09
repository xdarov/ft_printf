/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorina <pcorina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:37:17 by pcorina           #+#    #+#             */
/*   Updated: 2022/01/09 13:57:28 by pcorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_u(unsigned int num, int *result)
{
	char	str[20];
	long	l;
	int		i;

	l = num;
	if (l < 0)
		l = -l;
	i = 0;
	while (l != 0 || i == 0)
	{
		str[i] = l % 10 + 48;
		i++;
		l /= 10;
	}
	str[i] = '\0';
	*result += ft_strlen(str);
	ft_revers(str);
}

void	flag_p(unsigned long long link, int *result)
{
	write(1, "0x", 2);
	*result += 2;
	ft_hexadecimal(link, result, 'a');
}

void	flag_s(char *str, int *result)
{
	if (!str)
	{
		write(1, "(null)", 6);
		*result += 6;
		return ;
	}
	write(1, str, ft_strlen(str));
	*result += ft_strlen(str);
}

void	flag_xX(unsigned int num, int *result, char a)
{
	if (a == 'a')
		ft_hexadecimal(num, result, 'a');
	else if (a == 'A')
		ft_hexadecimal(num, result, 'A');
}

void	flag_id(int num, int *result)
{
	char	str[15];
	long	l;
	int		i;

	l = num;
	if (l < 0)
	{
		write(1, "-", 1);
		*result += 1;
		l = -l;
	}
	i = 0;
	while (l != 0 || i == 0)
	{
		str[i] = l % 10 + 48;
		i++;
		l /= 10;
	}
	str[i] = '\0';
	*result += ft_strlen(str);
	ft_revers(str);
}
