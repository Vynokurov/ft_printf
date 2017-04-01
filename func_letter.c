/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_letter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 17:57:44 by dvynokur          #+#    #+#             */
/*   Updated: 2017/02/18 17:57:47 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		f_type(p_list *data)
{
	char c;

	c = data->conv_letter;
	if ((c == 's') && (ft_strcmp(data->size_mod, "l") != 0))
		return (0);
	if (c == 'p')
		return (1);
	if (c == 'd' || c == 'D' || c == 'i')
		return (2);
	if (c == 'o' || c == 'O')
		return (3);
	if (c == 'u' || c == 'U')
		return (4);
	if (c == 'x' || c == 'X')
		return (5);
	if (c == 'c' || c == '%' || c == 'C')
		return (6);
	if (c == 'b')
		return (7);
	if ((c == 'S') || ((c == 's') && (ft_strcmp(data->size_mod, "l") == 0)))
		return (8);
	if (c != 's' || c != 'S' || c != 'p' || c != 'd' || c != 'D' || c != 'i' ||
		c != 'o' || c != 'O' || c != 'u' || c != 'U' || c != 'x' || c != 'X' ||
		c != 'c' || c != 'C' || c != '%')
		return (6);
	return (10);
}

size_t	len_calc(uintmax_t d, int n)
{
	size_t i;

	i = 0;
	if (d == 0)
		return (1);
	while(d > 0)
	{
		d = d / n;
		i++;
	}
	return (i);
}

int		func_b(p_list *data, va_list *ap)
{
	uintmax_t	b;
	char		*num;
	int			min;
	int			len;
	char		c;

	min = -1;
	c = data->conv_letter;
	b = size_mod_x(data, ap);
	num = ft_itoa_base_u(b, 2, 0);
	len = ft_strlen(num);
	if (c_find(data->flags, '-') == 1)
		return (padding_d_min(data, len, num, min));
	else
		return(padding_d(data, len, num, min));
	return (0);
}

int		c_find(char *s, char c)
{
	int i;

	i = -1;
	while (s[++i])
		if (s[i] == c)
			return (1);
	return (0);
}

int	func_p(p_list *data, va_list *ap)
{
	uintmax_t 	p;
	char		*num;
	int			min;
	int			len;
	
	
	min = -1;
	p = va_arg(*ap, uintmax_t);
	num = ft_itoa_base_u(p, 16, 0);
	len = ft_strlen(num);
	if (c_find(data->flags, '-') == 1)
		return (padding_d_min(data, len, num, min));
	else
		return(padding_d(data, len, num, min));
	return (0);
}
