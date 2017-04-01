/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_func.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 17:41:33 by dvynokur          #+#    #+#             */
/*   Updated: 2017/02/25 17:41:34 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		padding_s(int width, int precision, int len, char a)
{
	if (width > len)
	{
		if ((precision == -1) || (precision >= width))
			return (ft_putchar_len(a, (width - len)));
		else
		{
			if (len >= precision)
				return ((len == 0) ? ft_putchar_len(a, width) :
					ft_putchar_len(a, width - precision));
			else
				return ((len == 0) ? ft_putchar_len(a, width) :
					ft_putchar_len(a, width - len));

		}
	}
	else
	{
		if (precision == 0)
			return (ft_putchar_len(a, width));
		if (precision > 0 && precision < width)
		{
			if (len >= precision)
				return ((len == 0) ? ft_putchar_len(a, width) :
					ft_putchar_len(a, width - precision));
			else
				return ((len == 0) ? ft_putchar_len(a, width) :
					ft_putchar_len(a, width - len));				
		}
	}
	return (0);
}

int	func_S(p_list *data, va_list *ap)
{
	wchar_t	*s;
	int		len;
	char	a;
	int		ret;

	a = ' ';
	ret = 0;
	len = 0;
	s = va_arg(*ap, wchar_t *);
	if (s == NULL)
	  	s = L"(null)";
	len = counting_S(s);
	if (c_find(data->flags, '0') == 1)
		a = '0';
	if (c_find(data->flags, '-') == 1)
	{
		ret = ft_put_S(s, data->precision);
		ret += padding_s(data->width, data->precision, len, a);
	}
	else
	{
		ret = padding_s(data->width, data->precision, len, a);	
		ret += ft_put_S(s, data->precision);
	}
	return (ret);
}

int	func_s(p_list *data, va_list *ap)
{
	char	*s;
	int		len;
	char	a;
	int		ret;

	a = ' ';
	ret = 0;
	len = 0;
	s = va_arg(*ap, char*);
	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if (c_find(data->flags, '0') == 1)
		a = '0';
	if (c_find(data->flags, '-') == 1)
	{
		ret = ft_putstr_len(s, data->precision);
		ret += padding_s(data->width, data->precision, len, a);
	}
	else
	{
		ret = padding_s(data->width, data->precision, len, a);
		ret += ft_putstr_len(s, data->precision);
	}
	return (ret);
}

int		ft_putstr_len(char *str, int precision)
{
	int		i;

	i = 0;
	if (precision == -1)
	{
		while(str[i])
			write(1, &str[i++], 1);
	}
	else if (precision > 0)
	{
		while(str[i] && precision)
		{
			write(1, &str[i++], 1);
			precision--;
		}
	}
	return (i);
}

int		ft_putchar_len(char c, int width)
{
	int		i;

	i = 0;
	while (width--)
	{
		i++;
		write(1, &c, 1);
	}
	return (i);
}
