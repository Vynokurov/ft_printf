/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 19:24:08 by dvynokur          #+#    #+#             */
/*   Updated: 2017/02/15 19:25:41 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdint.h>

typedef struct 			print_list
{
	char				*flags;
	int					width;
	int					precision;
	char				*size_mod;
	char				conv_letter;
	int					i_after;
	struct print_list	*next;
}						p_list;
void					f_flag(p_list *data, char *str);
void					f_width(p_list *data, char *str, va_list *ap);
void					f_precision(p_list *data, char *str, va_list *ap);
void					f_size(p_list *data, char *str);
int						f_type(p_list *data);
int						func_s(p_list *data, va_list *ap);
int						func_p(p_list *data, va_list *ap);
int						func_d(p_list *data, va_list *ap);
int						func_o(p_list *data, va_list *ap);
int						func_u(p_list *data, va_list *ap);
int						func_x(p_list *data, va_list *ap);
int						func_c(p_list *data, va_list *ap);
int						func_C(p_list *data, va_list *ap);
int						func_b(p_list *data, va_list *ap);
int						func_S(p_list *data, va_list *ap);
int 					func_percent(p_list *data);
int						ft_printf(const char *format, ...);
int						c_find(char *s, char c);
size_t					len_calc(uintmax_t d, int n);
int						ft_putstr_len(char *str, int precision);
int						ft_putchar_len(char c, int width);
int						padding_s(int width, int precision, int len, char a);
int						sign_printing(char *flags, int d);
int						sign_checking(char *flags, int d);
int						k_count(char *str, int i);
void					f_width_star(p_list **data, char *str, va_list *ap);
void					f_width_star_dot(p_list **data, char *s1, char *s2, va_list *ap);
char					*ft_itoa_max(intmax_t n);
uintmax_t				size_mod_u(p_list *data, va_list *ap);
int						padding_d_min(p_list *data, int len, char *d, int min);
int						padding_d(p_list *data, int len, char *d, int min);
intmax_t				size_mod(p_list *data, va_list *ap);
char					*ft_itoa_base_u(uintmax_t n, int base, int up);
int						padding_char(p_list *data, char a);

uintmax_t				size_mod_x(p_list *data, va_list *ap);
//int						shifting_bytes(p_list *data, unsigned int c, size_t len);
//int						padding_wchar(p_list *data, b_char *a);
int						shifting_bytes(unsigned int c);
int 					padding_wchar(p_list *data, unsigned int c, int n);
int						counting_S(wchar_t *s);
int						ft_put_S(wchar_t *s, int precision);
int 					char_len(unsigned int c);


#endif