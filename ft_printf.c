/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:09:19 by dvynokur          #+#    #+#             */
/*   Updated: 2017/02/12 19:09:26 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	(*arg_manipulating[10])(p_list *data, va_list *ap) = {func_s, func_p,
	func_d, func_o, func_u, func_x, func_c, func_b, func_S};


p_list	*struct_making(void)
{
	p_list *data;
	
	if (!(data = (p_list *)malloc(sizeof(p_list))))
		return (NULL);
	data->flags = ft_strnew(5);
	data->width = 0;
	data->precision = -1;
	data->size_mod = ft_strnew(2);
	data->conv_letter = '\0';
	data->i_after = 0;
	data->next = NULL;
	return (data);
}

p_list	*str_analysing(char *str, va_list *ap)
{
	p_list	*data;
	p_list	*temp;
	char	*s;
	int		i;
	int		k;

	s = NULL;
	data = struct_making();
	temp = data;
	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			k = k_count(str, i);
			s = ft_strsub(str, i + 1, (k - i - 1));
			f_width(data, s, ap);
			free(s);
			data->conv_letter = str[k];
			data->i_after = k + 1;
			data->next = struct_making();
			data = data->next;
			i = k;
		}
		i++;
	}
	return (temp);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	p_list	*str_info;
	int i;
	int count;

	i = 0;
	count = 0;
		va_start(ap, format);
	str_info = str_analysing((char *)format, &ap);

	while (format[i])
	{
		if (format[i] == '%')
		{
			
			count += arg_manipulating[f_type(str_info)](str_info, &ap);
			i = str_info->i_after;
			str_info = str_info->next;
		}
		else
		{
			ft_putchar(format[i++]);
			count++;
		}
	}
	// while(format[i])
	// {
		

	// 	if (format[i] == '%' && format[i + 1] != '%' && str_info->conv_letter != '\0')
	// 	{
	// 		count += arg_manipulating[f_type(str_info->conv_letter)](str_info, &ap);


	// 		while (format[i] != str_info->conv_letter)
	// 			i++;
	// 		i++;
	// 		str_info = str_info->next;
	// 			}		
	// 	else
	// 	{
	// 		ft_putchar(format[i++]);
	// 		count++;
	// 	}
	// }
	
	va_end(ap);
	
	return (count);
}
