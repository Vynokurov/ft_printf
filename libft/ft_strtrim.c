/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 21:23:26 by dvynokur          #+#    #+#             */
/*   Updated: 2016/12/13 20:18:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		j;
	size_t		k;
	int			l;
	char		*res;

	k = 0;
	j = 0;
	if (!s)
		return (NULL);
	i = ft_strlen(s);
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j++;
	while (s[i - 1] == ' ' || s[i - 1] == '\n' || s[i - 1] == '\t')
		i--;
	l = i - j;
	if (l <= 0)
		l = 0;
	res = (char *)malloc(sizeof(char) * l + 1);
	if (!res)
		return (NULL);
	while (j < i)
		res[k++] = s[j++];
	res[k] = '\0';
	return (res);
}
