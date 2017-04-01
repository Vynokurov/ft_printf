/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:08:42 by dvynokur          #+#    #+#             */
/*   Updated: 2017/02/02 20:40:20 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*n;
	size_t		i;

	i = 0;
	n = (char *)malloc(sizeof(char) * size + 1);
	if (!n)
		return (0);
	while (size--)
	{
		n[i] = '\0';
		i++;
	}
	n[i] = '\0';
	return (n);
}
