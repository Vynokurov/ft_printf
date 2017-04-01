/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:19:07 by dvynokur          #+#    #+#             */
/*   Updated: 2016/12/09 20:37:43 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;

	if (*alst)
	{
		while (*alst)
		{
			ptr = *alst;
			del(ptr->content, ptr->content_size);
			free(ptr);
			*alst = (*alst)->next;
		}
		*alst = NULL;
	}
}
