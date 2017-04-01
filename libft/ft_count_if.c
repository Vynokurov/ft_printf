/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 14:57:00 by dvynokur          #+#    #+#             */
/*   Updated: 2016/12/11 14:55:06 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_if(char **tab, int (*f)(char*))
{
	size_t i;
	size_t number;

	i = 0;
	number = 0;
	while (tab[i])
	{
		if (f(tab[i]) == 1)
			number++;
		i++;
	}
	return (number);
}
