/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:47:04 by dvynokur          #+#    #+#             */
/*   Updated: 2016/12/03 17:59:50 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char*)s1;
	b = (unsigned char*)s2;
	while (n--)
	{
		if (a[i] == b[i])
			i++;
		else
			return (a[i] - b[i]);
	}
	return (0);
}
