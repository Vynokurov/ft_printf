/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C_func.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 19:17:06 by dvynokur          #+#    #+#             */
/*   Updated: 2017/03/25 19:17:09 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		shifting_bytes(unsigned int c)
{
	unsigned int	mask;
	int 			num;

	num = char_len(c);
	if (num == 1)
	{
		ft_putchar((char)c);
		return (1);
	}
	if (num == 2)
	{
		mask = 49280;
		ft_putchar((mask >> 8) | (c >> 6));
		ft_putchar((mask & ~65280) | (c & ~1984));
		return (2);
	}
	else if (num == 3)
	{
		mask = 14712960;
		ft_putchar((mask >> 16) | (c >> 12));
		ft_putchar((mask >> 8 & ~65280) | (c >> 6 & ~65472));
		ft_putchar((mask & ~16711680) | (c & ~65472));
		return (3);
	}
	else if (num == 4)
	{
		mask = 4034953344;
		ft_putchar((mask >> 24) | (c >> 18));
		ft_putchar((mask >> 16 & ~65280) | (c >> 12 & ~2097088));
		ft_putchar((mask >> 8 & ~16711680) | (c >> 6 & ~2097088));
		ft_putchar(mask & ~4278190080);
		return (4);
	}
	return (0);
}

int		counting_S(wchar_t *s)
{
	int i;
	int	count;
	int num;

	i = 0;
	count = 0;
	num = 0;
	while (s[i] != '\0')
	{
		num = char_len(s[i]);
		if (num == 1)
			count++;
		else if (num == 2)
			count += 2;
		else if (num == 3)
			count += 3;
		else
			count += 4;
		i++;
	}
	return (count);
}

int		ft_put_S(wchar_t *s, int precision)
{
	int i;
	int count;
	char 	*num;

	i = -1;
	count = 0;
	if (precision == -1)
	{

		while (s[++i])
			shifting_bytes(s[i]);
		count = counting_S(s);
	}
	else
	{
		while(s[++i] && (precision > 0))
		{
			num = ft_itoa_base_u(s[i], 2, 0);
			if (ft_strlen(num) <= 7)
			{
				ft_putchar ((char)s[i]);
				precision--;
				count++;
			}
			else
			{
				if ((precision -= char_len(s[i])) > 0)
					count += shifting_bytes(s[i]);
				else
					return (count);
			}
		}
	}
	return (count);
}

int 	char_len(unsigned int c)
{
	char *num;

	num = ft_itoa_base_u(c, 2, 0);
	if (ft_strlen(num) <= 7)
		return (1);
	else if (ft_strlen(num) <= 11)
		return (2);
	else if (ft_strlen(num) <= 16)
		return (3);
	else
		return (4);
	return (0);
}

int		padding_wchar(p_list *data, unsigned int a, int n)
{
	char	c;
	int		i;

	i = 0;
	(c_find(data->flags, '0') == 1) ? (c = '0') : (c = ' ');
	if ((data->width - n) >= 1)
	{
		if (c_find(data->flags, '-') == 1)
		{
			shifting_bytes(a);
			while (i < (data->width - n))
			{
				ft_putchar(' ');
				i++;
			}
			return (data->width);
		}
		else
		{
			while (i < (data->width - n))
			{
				ft_putchar(c);
				i++;
			}
			shifting_bytes(a);
			return (data->width);
		}
	}
	else
	{
		shifting_bytes(a);
		return (n);
	}
	return (0);
}
