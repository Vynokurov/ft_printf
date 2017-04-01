/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_func.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 14:26:55 by dvynokur          #+#    #+#             */
/*   Updated: 2017/03/11 14:26:56 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	size_mod_u(p_list *data, va_list *ap)
{
	uintmax_t	u;
	char		*s;
	char		c;

	u = 0;
	s = data->size_mod;
	c = data->conv_letter;
	if (((ft_strcmp(s, "") == 0) && (c == 'u')) && (u = (unsigned int)va_arg(*ap, intmax_t)))
		return (u);
	if (((ft_strcmp(s, "hh") == 0) && (c == 'u')) && (u = (unsigned char)va_arg(*ap, intmax_t)))
		return (u);
	if (((ft_strcmp(s, "h") == 0) && (c == 'u')) && (u = (unsigned short)va_arg(*ap, intmax_t)))
		return (u);
	if ((((ft_strcmp(s, "l") == 0) && (c == 'u')) || (c == 'U')))
	{
		u = (unsigned long)va_arg(*ap, intmax_t);
		return (u);
	}
	if ((ft_strcmp(s, "ll") == 0) && (u = (unsigned long long)va_arg(*ap, intmax_t)))
		return (u);
	if ((ft_strcmp(s, "j") == 0) && (u = (uintmax_t)va_arg(*ap, intmax_t)))
		return (u);
	if ((ft_strcmp(s, "z") == 0) && (u = (size_t)va_arg(*ap, intmax_t)))
		return (u);
	return (0);
}

char		*ft_itoa_max_u(uintmax_t b)
{
	char		*res;
	size_t		len;
		
	len = len_calc(b, 10);
	res = (char*)malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (len--)
	{
		res[len] = b % 10 + '0';
		b = b / 10;
	}
	return (res);
}

int	func_u(p_list *data, va_list *ap)
{
	uintmax_t	u;
	char		*num;
	int			min;
	int			len;
	char c;

	min = -1;
	c = data->conv_letter;
	u = size_mod_u(data, ap);
	
	num = ft_itoa_max_u(u);
	len = ft_strlen(num);
	if (c_find(data->flags, '-') == 1)
		return (padding_d_min(data, len, num, min));
	else
		return(padding_d(data, len, num, min));
	return (0);
}
