/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:19:17 by quroulon          #+#    #+#             */
/*   Updated: 2016/06/03 16:30:50 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <locale.h>
# include <limits.h>

# define UI unsigned int
# define US unsigned short
# define UC unsigned char

typedef struct		s_env
{
	int				flag_l;
	int				flag_ll;
	int				flag_h;
	int				flag_hh;
	int				flag_j;
	int				flag_z;
	int				flag_pt;
	int				flag_d;

	int				flag_dz;
	int				flag_zr;
	int				flag_ms;
	int				flag_ps;
	int				flag_sp;

	int				maj;
	int				nb_sp;
	char			conv;
	int				nb_char;
	int				nb_arg;
	const char		*str;
}					t_env;

/*
**	ft_printf.c
*/
int					ft_printf(const char *format, ...);

/*
**	utilities.c
*/
void				ft_error(t_env *env);

/*
**	flags.c
*/
void				ft_initflag(const char *format, t_env *env, int *j);
void				ft_initconv(int *i, t_env *env, va_list ap);

/*
**	va_list.c
*/
void				ft_useva(t_env *env, va_list ap);
void				flag_rien(t_env *env);
void				flag_pourcent(t_env *env);
void				flag_wchar(t_env *env, va_list ap);
void				flag_char(t_env *env, va_list ap);
void				flag_unsigned(unsigned long long a, t_env *env, va_list ap);
void				flag_str(t_env *env, va_list ap, int nul, char *tmp);
void				flag_wstr(t_env *env, va_list ap, int nul, int i);

/*
**	ft_space.c
*/
void				ft_space_int(long long a, t_env *env);
void				ft_space_str(char *str, t_env *env);
void				ft_space_char(char c, t_env *env);
void				ft_space_wchar(int a, t_env *env, int seis, UI *bit);
void				ft_putarg_wstr(t_env *env, wchar_t *str);
void				flag_octal(long long a, t_env *env, va_list ap);
void				flag_octal2(long long a, t_env *env, char **str);
void				flag_hexa(long long a, t_env *env, va_list ap);

/*
**	ft_forstr.c
*/
void				ft_null_str(char **str);
void				ft_null_wstr(wchar_t **str);
char				*ft_modifstr(char *str, t_env *env);
wchar_t				*ft_modifwstr(wchar_t *str, t_env *env, int i, int place);

/*
**	flags_application.c
*/
void				flag_dz_str(t_env *env, char *str);
void				ft_putarg_str(t_env *env, char *str, int i, int surplus);
void				ft_putarg_ll(t_env *env, long long a);

void				flag_pt_xo(t_env *env, char *str);

/*
**	ft_init.c
*/
void				ft_initenv(t_env *env);
void				ft_initdigit(t_env *env, int *i);
int					ft_verifbase(t_env *env, int *i);
void				ft_veriflh(t_env *env, int *i, int *tmpl, int *tmph);
int					ft_verifchar(char c);

/*
** ft_gestion.c
*/
void				ft_maxtype(t_env *e);

/*
**	libft_ull
*/
void				ft_putnbr_ull(unsigned long long nb);
void				ft_putnbr_ul(unsigned long nb);
void				ft_putnbr_ui(unsigned int nb);
void				ft_putnbr_ll(long long nb);
void				ft_putnbr_l(long nb);

int					ft_nbrlen_ull(unsigned long long n);
int					ft_nbrlen_ul(unsigned long n);
int					ft_nbrlen_ui(unsigned int n);
int					ft_nbrlen_ll(long long n);
int					ft_nbrlen_l(long n);

char				*ft_itoabase_ull(unsigned long long n, int base, int maj);
char				*ft_itoabase_ui(unsigned int n, int base, int maj);
char				*ft_itoabase_uc(unsigned char n, int base, int maj);
char				*ft_itoabase_us(unsigned short n, int base, int maj);
int					ft_wstrlen(wchar_t *str);

#endif
