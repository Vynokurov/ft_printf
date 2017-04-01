/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 11:50:03 by dvynokur          #+#    #+#             */
/*   Updated: 2016/12/09 19:24:01 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_count(int n)
{
	size_t		i;
	long int	b;

	b = (long int)n;
	i = 0;
	if (b < 0)
	{
		i = 1;
		b *= -1;
	}
	while (b > 0)
	{
		b = b / 10;
		i++;
	}
	if (n < 10 && n >= 0)
		return (1);
	return (i);
}

char		*ft_itoa(int n)
{
	char			*res;
	unsigned int	i;
	long int		b;
	int				a;

	a = 1;
	b = (long int)n;
	if (n < 0)
	{
		a = -1;
		b *= -1;
	}
	i = len_count(n);
	res = (char*)malloc(sizeof(char) * i + 1);
	if (!res)
		return (NULL);
	res[i] = '\0';
	while (i--)
	{
		res[i] = b % 10 + '0';
		b = b / 10;
	}
	if (a == -1)
		res[0] = '-';
	return (res);
}
