/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 15:20:43 by dvynokur          #+#    #+#             */
/*   Updated: 2016/12/04 17:13:32 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*n;

	n = (void *)malloc(sizeof(n) * size + 1);
	if (!n)
		return (0);
	ft_bzero(n, size);
	return (n);
}
