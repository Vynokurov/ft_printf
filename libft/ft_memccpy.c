/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:46:02 by dvynokur          #+#    #+#             */
/*   Updated: 2016/12/02 20:51:41 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;
	unsigned char	d;

	i = 0;
	a = (unsigned char*)src;
	b = (unsigned char*)dst;
	d = (unsigned char)c;
	while (n != 0)
	{
		b[i] = a[i];
		if (a[i] == d)
		{
			b[i] = a[i];
			return (dst + i + 1);
		}
		i++;
		n--;
	}
	return (0);
}
