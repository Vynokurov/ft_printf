/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 20:09:46 by dvynokur          #+#    #+#             */
/*   Updated: 2017/02/19 20:09:48 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>
#include <locale.h>
#include <limits.h>

int		main(void)
{
  unsigned char c;
  int   a = 10;
  unsigned long l = 388844455535566;
  char *locale;

  locale = setlocale(LC_ALL, "");
  
  printf("|  %d\n", ft_printf("{%*3d}", 5, 0));
  printf("\n");
  printf("|  %d\n", printf("{%*3d}", 5, 0));

	return (0);
}

// "%#-08x", 42

// 4294967295
//ffffffff
// 4294967295

/*

UCHAR_MAX - 255 + 42 = 451

 && ((ft_strcmp(s, "ll") != 0) || 
    (ft_strcmp(s, "j") != 0) || (ft_strcmp(s, "z") != 0))

*/

