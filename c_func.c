/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_func.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 13:30:50 by dvynokur          #+#    #+#             */
/*   Updated: 2017/03/23 13:30:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	func_c(p_list *data, va_list *ap)
{
	unsigned int 	c;
	unsigned char 	oct;
	int				num;
	
	if (data->conv_letter == '%')
		return (padding_char(data, '%'));
	if ((data->conv_letter == 'c' && (ft_strcmp(data->size_mod, "l") == 0)) || (data->conv_letter == 'C'))
	{
		c = va_arg(*ap, int);
		num = char_len(c);
		if (num == 1)
			return (padding_char(data, (unsigned char)c));
		else if (num == 2)
			return (padding_wchar(data, c, 2));
		else if (num == 3)
			return (padding_wchar(data, c, 3));
		else
			return (padding_wchar(data, c, 4));
	}
	if (data->conv_letter == 'c')
	{
		c = va_arg(*ap, int);
		return (padding_char(data, (char)c));
	}
	if (data->conv_letter != '%' && data->conv_letter != 'c' && data->conv_letter != 'C')
		return (padding_char(data, data->conv_letter));
	return (0);
}

int		padding_char(p_list *data, char a)
{
	char	c;
	int		i;

	i = 0;
	(c_find(data->flags, '0') == 1) ? (c = '0') : (c = ' ');
	if (data->width >= 1)
	{
		if (c_find(data->flags, '-') == 1)
		{
			ft_putchar(a);
			while (i < (data->width - 1))
			{
				ft_putchar(' ');
				i++;
			}
			return (data->width);
		}
		else
		{
			while (i < (data->width - 1))
			{
				ft_putchar(c);
				i++;
			}
			ft_putchar(a);
			return (data->width);
		}
	}
	else
	{
		ft_putchar(a);
		return (1);
	}
	return (0);
}
