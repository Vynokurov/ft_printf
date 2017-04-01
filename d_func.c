/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_func.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 19:20:05 by dvynokur          #+#    #+#             */
/*   Updated: 2017/03/03 19:20:08 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		padding_d_min(p_list *data, int len, char *d, int min)
{
	intmax_t	ret;
	char		*s;
	int 		l;

	s = ft_strnew(2);
	ret = 0;
	if ((c_find(data->flags, '#') == 1) || data->conv_letter == 'p')
	{
		if (data->conv_letter == 'x' || data->conv_letter == 'p')
			s = "0x";
		if (data->conv_letter == 'X')
			s = "0X";
		if (data->conv_letter == 'o' || data->conv_letter == 'O')
			s = "0";
	}
	l = ft_strlen(s);
	ret = sign_printing(data->flags, min);
	if (len >= data->width)
	{
		if (len >= data->precision)
		{
			if (data->precision == 0 && d[0] == '0')
			{
				d = "";
				len = 0;
				if (data->conv_letter == 'x' || data->conv_letter == 'X')
				{
					s = "";
					l = 0;
				}
			}
			if (data->precision == -1 && d[0] == '0' && l > 0 && data->conv_letter != 'p')
			{
				s = "";
				l = 0;
			}
			ft_putstr(s);
			ft_putstr(d);
			return (len + ret + l);
		}
		else
		{
			ft_putstr(s);
			ret += ft_putchar_len('0', (data->precision - len));
			ft_putstr(d);
			return (ret + (data->precision - len) + l);
		}
	}
	else
	{
		if (len >= data->precision)
		{
			if (data->precision == 0 && d[0] == '0')
			{
				d = "";
				len = 0;
			}
			ft_putstr(s);
			ft_putstr(d);
			ret += ft_putchar_len(' ', (data->width - l - (len + sign_checking(data->flags, min))));
			return (data->width);
		}
		else
		{
			if (data->width >= data->precision)
			{
				ft_putstr(s);
				ret += ft_putchar_len('0', (data->precision - len));
				ft_putstr(d);
				ret += ft_putchar_len(' ', (data->width - l - data->precision - sign_checking(data->flags, min)));
				return (data->width + l);
			}
			else
			{
				ft_putstr(s);
				ret += ft_putchar_len('0', (data->precision - len));
				ft_putstr(d);
				return (data->precision + l);
			}
		}
	}
	return (ret);
}

int		padding_d(p_list *data, int len, char *d, int min)
{
	intmax_t ret;
	char	*s;
	int 		l;

	ret = 0;
	s = ft_strnew(2);
		if ((c_find(data->flags, '#') == 1) || data->conv_letter == 'p')
	{
		if (data->conv_letter == 'x' || data->conv_letter == 'p')
			s = "0x";
		if (data->conv_letter == 'X')
			s = "0X";
		if (data->conv_letter == 'o' || data->conv_letter == 'O')
			s = "0";
	}
	l = ft_strlen(s);
	if (len >= data->width)
	{
		if (len >= data->precision)
		{
			if (data->precision == 0 && d[0] == '0')
			{
				d = "";
				len = 0;
				if (data->conv_letter == 'x' || data->conv_letter == 'X')
				{
					s = "";
					l = 0;
				}
			}
			if (data->precision == -1 && d[0] == '0' && l > 0 && data->conv_letter != 'p')
			{
				s = "";
				l = 0;
			}
			ft_putstr(s);
			ret = sign_printing(data->flags, min);
			ft_putstr(d);
			return (len + ret + l);
		}
		else
		{
			if ((c_find(data->flags, '#') == 1) && (data->conv_letter == 'o' || data->conv_letter == 'O'))
			{
				s = "";
				l = 0;
			}
			ft_putstr(s);
			ret = sign_printing(data->flags, min);
			ret += ft_putchar_len('0', (data->precision - len));
			ft_putstr(d);
			return (data->precision + sign_checking(data->flags, min) + l);
		}
	}
	else
	{

		if (len >= data->precision)
		{

			if ((c_find(data->flags, '0') == 1) && data->precision == -1)
			{
				ft_putstr(s);
				ret = sign_printing(data->flags, min);
				ret += ft_putchar_len('0', (data->width - l - (len + sign_checking(data->flags, min))));
				ft_putstr(d);
				return (data->width);
			}
			else
			{
				if (data->precision == 0 && d[0] == '0')
				{
					d = "";
					len = 0;
				}
				ret = ft_putchar_len(' ', (data->width - l - (len + sign_checking(data->flags, min))));
				ret += sign_printing(data->flags, min);
				ft_putstr(s);
				ft_putstr(d);
				return (data->width);
			}
		}
		else
		{

			if (data->width >= data->precision)
			{
				ft_putstr(s);
				ret = ft_putchar_len(' ', (data->width - l - (data->precision + sign_checking(data->flags, min))));
				ret += sign_printing(data->flags, min);
				ret += ft_putchar_len('0', (data->precision - len));
				ft_putstr(d);
				return (data->width);
			}
			else
			{
				ft_putstr(s);
				ret += sign_printing(data->flags, min);
				ret += ft_putchar_len('0', (data->precision - len));
				ft_putstr(d);
				return (len + ret + l);
			}
		}
	}
	return (0);
}

int		sign_checking(char *flags, int min)
{
	if (min == -1)
		return (0);
	if (min == 1)
		return (1);
	if (c_find(flags, '+') == 1)
		return (1);
	if (c_find(flags, ' ') == 1)
		return (1);
	return (0);
}

int		sign_printing(char *flags, int min)
{
	int n;
	n = 0;
	if (min == -1)
		return (0);
	if (min == 1)
	{
		write(1, "-", 1);
		return (1);
	}
	if (c_find(flags, '+') == 1)
	{
		write(1, "+", 1);
		return (1);
	}
	if (c_find(flags, ' ') == 1)
	{
		write(1, " ", 1);
		return (1);
	}
	return (0);
}



intmax_t	size_mod(p_list *data, va_list *ap)
{
	intmax_t	d;
	char		*s;
	char		c;

	d = 0;
	s = data->size_mod;
	c = data->conv_letter;
	if (((ft_strcmp(s, "") == 0) && (c != 'D')) && (d = (int)va_arg(*ap, intmax_t)))
		return (d);
	if (((ft_strcmp(s, "hh") == 0) && (c != 'D')) && (d = (char)va_arg(*ap, intmax_t)))
		return (d);
	if (((ft_strcmp(s, "h") == 0) && (c != 'D')) && (d = (short)va_arg(*ap, intmax_t)))
		return (d);
	if ((ft_strcmp(s, "l") == 0) || (c == 'D'))
	{
		d = (long)va_arg(*ap, intmax_t);
		return (d);
	}
	if ((ft_strcmp(s, "ll") == 0) && (d = (long long)va_arg(*ap, intmax_t)))
		return (d);
	if ((ft_strcmp(s, "j") == 0) && (d = (intmax_t)va_arg(*ap, intmax_t)))
		return (d);
	if ((ft_strcmp(s, "z") == 0) && (d = (size_t)va_arg(*ap, intmax_t)))
		return (d);
	return (0);
}




// intmax_t	size_mod(p_list *data, va_list *ap)
// {
// 	intmax_t	d;
// 	char		*s;

// 	d = 0;
// 	s = data->size_mod;
// 	if ((ft_strcmp(s, "") == 0) && (d = (int)va_arg(*ap, intmax_t)))
// 		return (d);
// 	if ((ft_strcmp(s, "hh") == 0) && (d = (char)va_arg(*ap, intmax_t)))
// 		return (d);
// 	if ((ft_strcmp(s, "h") == 0) && (d = (short)va_arg(*ap, intmax_t)))
// 		return (d);
// 	if ((ft_strcmp(s, "l") == 0) && (d = (long)va_arg(*ap, intmax_t)))
// 		return (d);
// 	if ((ft_strcmp(s, "ll") == 0) && (d = (long long)va_arg(*ap, intmax_t)))
// 		return (d);
// 	if ((ft_strcmp(s, "j") == 0) && (d = (intmax_t)va_arg(*ap, intmax_t)))
// 		return (d);
// 	if ((ft_strcmp(s, "z") == 0) && (d = (size_t)va_arg(*ap, intmax_t)))
// 		return (d);
// 	return (0);
// }

int			func_d(p_list *data, va_list *ap)
{
	intmax_t	d;
	int			len;
	int			ret;
	int			min;
	char		*num;

	ret = 0;
	min = 0;
	d = size_mod(data, ap);
	d < 0 ? (min = 1) : (min = 0);
	num = ft_itoa_max(d);
	len = ft_strlen(num);
	if (c_find(data->flags, '-') == 1)
		return (padding_d_min(data, len, num, min));
	else
		return(padding_d(data, len, num, min));
	return (0);
}

char		*ft_itoa_max(intmax_t n)
{
	char		*res;
	size_t		len;
	uintmax_t	b;
	
	n < 0 ? (b = n * (-1)) : (b = n);

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

