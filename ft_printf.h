/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorina <pcorina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:36:58 by pcorina           #+#    #+#             */
/*   Updated: 2021/10/25 16:02:57 by pcorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
void	ft_hexadecimal(unsigned long long num, int *result, char a);
int		ft_printf(const char *str, ...);
void	ft_revers(char *str);
void	flag_p(unsigned long long link, int *result);
void	flag_id(int num, int *result);
void	flag_u(unsigned int num, int *result);
void	flag_xX(unsigned int num, int *result, char a);
void	flag_s(char *str, int *result);
#endif