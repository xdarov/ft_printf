/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorina <pcorina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:37:29 by pcorina           #+#    #+#             */
/*   Updated: 2022/01/09 13:53:05 by pcorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_result(char c, int *result)
{
	write(1, &c, 1);
	*result += 1;
}

int	chek(char ch )
{
	if (ch == 'c')
		return ((int)ch);
	if (ch == 's')
		return ((int)ch);
	if (ch == 'p')
		return ((int)ch);
	if (ch == 'd')
		return ((int)ch);
	if (ch == 'i')
		return ((int)ch);
	if (ch == 'u')
		return ((int)ch);
	if (ch == 'x')
		return ((int)ch);
	if (ch == 'X')
		return ((int)ch);
	if (ch == '%')
		return ((int)ch);
	return (0);
}

void	select_fun(char ch, va_list *arg_ptr, int *result)
{
	if (ch == 'c')
		ft_putchar_result(va_arg(*arg_ptr, int), result);
	if (ch == 's')
		flag_s(va_arg(*arg_ptr, char *), result);
	if (ch == 'p')
		flag_p(va_arg(*arg_ptr, unsigned long long), result);
	if (ch == 'd')
		flag_id(va_arg(*arg_ptr, int), result);
	if (ch == 'i')
		flag_id(va_arg(*arg_ptr, int), result);
	if (ch == 'u')
		flag_u(va_arg(*arg_ptr, int), result);
	if (ch == 'x')
		flag_xX(va_arg(*arg_ptr, unsigned int), result, 'a');
	if (ch == 'X')
		flag_xX(va_arg(*arg_ptr, unsigned int), result, 'A');
	if (ch == '%')
		ft_putchar_result(ch, result);
}

int	ft_printf(const char *str, ...)
{
	va_list		arg_ptr;
	char		*buf;
	int			result;

	va_start(arg_ptr, str);
	buf = (char *)str;
	result = 0;
	while (*buf)
	{
		if (*buf == '%' && chek(*(buf + 1)))
			select_fun(*++buf, &arg_ptr, &result);
		else if (*buf != '%')
		{
			write(1, buf, 1);
			result++;
		}
		buf++;
	}
	va_end(arg_ptr);
	return (result);
}
