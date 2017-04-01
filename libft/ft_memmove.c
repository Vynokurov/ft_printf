/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 20:52:06 by dvynokur          #+#    #+#             */
/*   Updated: 2016/12/02 21:58:12 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	i = 0;
	a = (unsigned char*)src;
	b = (unsigned char*)dst;
	if (a < b)
		while (len--)
			b[len] = a[len];
	else
		while (i < len)
		{
			b[i] = a[i];
			i++;
		}
	return (dst);
}
