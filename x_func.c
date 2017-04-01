/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_func.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 15:26:17 by dvynokur          #+#    #+#             */
/*   Updated: 2017/03/11 15:26:19 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	size_mod_x(p_list *data, va_list *ap)
{
	uintmax_t	x;
	char		*s;

	x = 0;
	s = data->size_mod;
	if ((ft_strcmp(s, "") == 0) && (x = (unsigned int)va_arg(*ap, intmax_t)))
		return (x);
	if ((ft_strcmp(s, "hh") == 0) && (x = (unsigned char)va_arg(*ap, intmax_t)))
		return (x);
	if ((ft_strcmp(s, "h") == 0)  && (x = (unsigned short)va_arg(*ap, intmax_t)))
		return (x);
	if ((ft_strcmp(s, "l") == 0) && (x = (unsigned long)va_arg(*ap, intmax_t)))
		return (x);
	if ((ft_strcmp(s, "ll") == 0) && (x = (unsigned long long)va_arg(*ap, intmax_t)))
		return (x);
	if ((ft_strcmp(s, "j") == 0) && (x = (uintmax_t)va_arg(*ap, uintmax_t)))
		return (x);
	if ((ft_strcmp(s, "z") == 0) && (x = (size_t)va_arg(*ap, intmax_t)))
		return (x);
	return (0);
}

char	*ft_itoa_base_u(uintmax_t n, int base, int m)
{
	char	low[] = "0123456789abcdef";
	char	up[] = "0123456789ABCDEF";
	char	*s;
	char	*res;
	int		len;

	(m > 0) ? (s = up) : (s = low);
	len = len_calc(n, base);
	res = (char*)malloc(sizeof(char) * len + 1);
	res[len] = '\0';
	len--;
	while (len >= 0)
	{
		res[len] = s[n % base];
		n = n / base;
		len--;
	}
	return (res);
}

int		func_x(p_list *data, va_list *ap)
{
	uintmax_t	x;
	char		*num;
	int			min;
	int			len;
	char		c;

	min = -1;
	c = data->conv_letter;
	x = size_mod_x(data, ap);
	(c == 'x') ? (num = ft_itoa_base_u(x, 16, 0)) : (num = ft_itoa_base_u(x, 16, 1));
	len = ft_strlen(num);
	if (c_find(data->flags, '-') == 1)
		return (padding_d_min(data, len, num, min));
	else
		return(padding_d(data, len, num, min));
	return (0);
}

int 	func_o(p_list *data, va_list *ap)
{
	uintmax_t	o;
	char		*num;
	int			min;
	int			len;
	char		c;

	min = -1;
	c = data->conv_letter;
	(c == 'O') ? (o = va_arg(*ap, uintmax_t)) : (o = size_mod_x(data, ap));
	(c == 'o') ? (num = ft_itoa_base_u(o, 8, 0)) : (num = ft_itoa_base_u(o, 8, 1));
	len = ft_strlen(num);
	if (c_find(data->flags, '-') == 1)
		return (padding_d_min(data, len, num, min));
	else
		return(padding_d(data, len, num, min));
	return (0);
}
