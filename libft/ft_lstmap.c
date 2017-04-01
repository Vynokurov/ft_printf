/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:42:34 by dvynokur          #+#    #+#             */
/*   Updated: 2016/12/13 18:15:46 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ptr;
	t_list	*ptr_frst;

	if (!lst || !f)
		return (0);
	ptr = f(lst);
	ptr_frst = ptr;
	while (lst->next)
	{
		ptr->next = f(lst->next);
		if (ptr->next == NULL)
			return (0);
		lst = lst->next;
		ptr = ptr->next;
	}
	return (ptr_frst);
}
