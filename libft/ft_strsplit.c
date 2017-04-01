/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 10:58:52 by dvynokur          #+#    #+#             */
/*   Updated: 2016/12/14 11:19:36 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**mem_free(char **res, int j)
{
	int i;

	i = 0;
	while (i < j)
		i++;
	while (i--)
		free(res[i]);
	free(res);
	return (NULL);
}

static int		word_counter(char const *s, char c)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if ((s[i] == c && s[i + 1] != c) || s[0] != c)
			j++;
		i++;
	}
	return (j);
}

static int		l_coun(char const *s, char c, int i)
{
	size_t a;

	a = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		a++;
	}
	return (a);
}

static char		**array_builder(char const *s, char c, char **res)
{
	size_t	i;
	size_t	j;
	size_t	k;

	j = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			k = 0;
			if (!(res[j] = (char*)malloc(sizeof(char) * l_coun(s, c, i) + 1)))
				return (mem_free(res, j));
			while (s[i] != c && s[i])
				res[j][k++] = s[i++];
			res[j++][k] = '\0';
		}
	}
	res[j] = 0;
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**res;

	if (!s)
		return (NULL);
	if (!(res = (char **)malloc(sizeof(char*) * word_counter(s, c) + 1)))
		return (NULL);
	res = array_builder(s, c, res);
	return (res);
}
