/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 19:50:33 by dvynokur          #+#    #+#             */
/*   Updated: 2016/12/11 20:33:31 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_push_back(t_list **start, void *content, size_t content_size)
{
	t_list *ptr;

	ptr = *start;
	if (ptr)
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = ft_lstnew(content, content_size);
	}
	else
		*start = ft_lstnew(content, content_size);
}
