/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_making.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 21:40:49 by dvynokur          #+#    #+#             */
/*   Updated: 2017/02/17 21:40:53 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		k_count(char *str, int i)
{
	i++;
	while (str[i])
	{
		if (str[i + 1] == '\0')
			return (i);
		if (str[i] == '-' || str[i] == '+' || str[i] == '0' || str[i] == ' '
		|| str[i] == '#' || (str[i] >= '0' && str[i] <= '9') || str[i] == '.'
		|| str[i] == '*' || str[i] == 'L' || str[i] == 'l' || str[i] == 'h'
		|| str[i] == 'j' || str[i] == 'z')
			i++;
		else
			return (i);
	}
	return (0);
}

void	f_flag(p_list *data, char *str)
{
	int		a;
	int		i;

	i = 1;
	a = 0;
	
	if (c_find(str, '-') == 1)
		data->flags[a++] = '-';
	if (c_find(str, '+') == 1)
		data->flags[a++] = '+';
	if (c_find(str, ' ') == 1)
		data->flags[a++] = ' ';
	if (c_find(str, '#') == 1)
		data->flags[a++] = '#';
	
	while (str[i])
	{
		if ((str[0] == '0') || (str[i] == '0' && !(str[i - 1] >= '0' &&
			str[i - 1] <= '9')))
			data->flags[a] = '0';
		i++;
	}

	f_size(data, str);
}

void	f_width(p_list *data, char *str, va_list *ap)
{
	int		i;

	i = 1;

	if (str[0] >= '0' && str[0] <= '9')
		data->width = ft_atoi(&str[0]);
	
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') && (str[i - 1] != '.') &&
			!(str[i - 1] >= '0' && str[i - 1] <= '9'))
		{
			data->width = ft_atoi(&str[i]);
			while (str[i] >= '0' && str[i] <= '9')
				i++;
		}
		else if (str[i] == '*' && str[i - 1] != '.')
			data->width = va_arg(*ap, int);
		i++;
	}
	f_flag(data, str);
	f_precision(data, str, ap);
}

void	f_precision(p_list *data, char *str, va_list *ap)
{
	int		i;
	
	
	i = -1;
	while (str[++i])
	{
		if (str[i] == '.')
			data->precision = 0;
		if (str[i] == '.' && str[i + 1] >= '1' && str[i + 1] <= '9')
			data->precision = ft_atoi(&str[i + 1]);
		if (str[i] == '.' && str[i + 1] == '0')
			data->precision = 0;
		if (str[i] == '.' && str[i + 1] == '*')
			data->precision = va_arg(*ap, int);

	}
}

int		f_size_h(char *str)
{
	int i;
	int last;


	i = 1;
	last = (ft_strlen(str) - 1);
	if (str[0] == 'h' && str[1] != 'h')
		return (1);
	if (str[last] == 'h' && str[last - 1] != 'h')
		return (1);
	if (last < 2)
		return (0);
	while (i != (last - 1))
	{
		if (str[i] == 'h' && str[i + 1] != 'h' && str[i - 1] != 'h')
			return (1);
		i++;
	}
	return (0);
}

void	f_size(p_list *p, char *str)
{
	int	i;
	int j;

	i = -1;
	j = 1;
	
	while (str[++i])
	{
		if ((c_find(str, 'j') == 1) && (p->size_mod[0] = 'j'))
			break;
		if ((c_find(str, 'z') == 1) && (p->size_mod[0] = 'z'))
			break;
		if ((ft_strstr(str, "ll") != NULL) && (p->size_mod[0] = 'l') && (p->size_mod[1] = 'l'))
			break;
		if ((c_find(str, 'l') == 1) && (p->size_mod[0] = 'l'))
			break;
		if ((f_size_h(str) == 1) && (p->size_mod[0] = 'h'))
			break;
		if ((ft_strstr(str, "hh") != NULL) && (p->size_mod[0] = 'h') && (p->size_mod[1] = 'h'))
			break;
	}
}

// void	f_conv_letter(p_list *data, char *s)
// {
// 	char c;
// 	int i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	c = s[i - 1];

// 	if (c == 'a' || c == 'A' || c == 'c' || c == 'd'
// 		|| c == 'e' || c == 'E' || c == 'f' || c == 'g'
// 		|| c == 'G' || c == 'i' || c == 'n' || c == 'o'
// 		|| c == 'p' || c == 's' || c == 'u' || c == 'x'
// 		|| c == 'X' || c == '%')
// 		data->conv_letter = c;
	

// }
