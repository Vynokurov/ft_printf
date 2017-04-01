/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 20:19:18 by dvynokur          #+#    #+#             */
/*   Updated: 2016/12/11 20:24:33 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_last(t_list *start)
{
	t_list	*ptr;

	ptr = start;
	while (ptr->next)
		ptr = ptr->next;
	return (ptr->content);
}
