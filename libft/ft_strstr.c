/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:45:14 by dvynokur          #+#    #+#             */
/*   Updated: 2016/12/04 18:07:44 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t i;
	size_t j;

	i = 0;
	if (little[i] == '\0')
		return ((char*)big);
	while (big[i])
	{
		j = 0;
		while (little[j] == big[j + i])
		{
			if (little[j + 1] == '\0')
				return ((char*)big + i);
			j++;
		}
		i++;
	}
	return (0);
}
