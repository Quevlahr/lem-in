/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 21:19:59 by quroulon          #+#    #+#             */
/*   Updated: 2016/06/03 17:00:49 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		flag_hexa2(long long *a, t_env *env, va_list ap)
{
	if (env->conv == 'p')
	{
		env->flag_dz = 1;
		*a = (long long)va_arg(ap, void*);
	}
	else if (env->flag_l == 1)
		*a = va_arg(ap, long);
	else if (env->flag_ll == 1)
		*a = va_arg(ap, long long);
	else if (env->flag_j == 1)
		*a = va_arg(ap, unsigned long long);
	else
		*a = va_arg(ap, int);
}

static void		flag_hexa3(long long *a, t_env *env, char **str, long long *val)
{
	if (*a > -2147483648 && env->flag_j == 0 && env->flag_l == 0 &&
			env->flag_ll == 0 && env->flag_z == 0)
		*val = *a < 0 ? 4294967296 + (long long)*a : (long long)*a;
	else
		*val = *a < 0 ? ULONG_MAX + 1 + (long long)*a : (long long)*a;
	if (env->flag_hh == 1)
		*str = ft_itoabase_uc(*val, 16, env->maj);
	else if (env->flag_h == 1)
		*str = ft_itoabase_us(*val, 16, env->maj);
	else
		*str = ft_itoabase_ull(*val, 16, env->maj);
}

void			flag_hexa(long long a, t_env *env, va_list ap)
{
	char		*str;
	char		*tmp;
	long long	value;

	tmp = NULL;
	str = NULL;
	env->flag_sp = 0;
	flag_hexa2(&a, env, ap);
	flag_hexa3(&a, env, &str, &value);
	if (env->flag_pt != 0 && ft_strcmp(str, "0") == 0 && env->conv != 'p')
	{
		env->flag_dz = 0;
		ft_strdel(&str);
		str = ft_strnew(0);
	}
	ft_space_str(str, env);
	ft_strdel(&str);
}

void			flag_int(long long a, t_env *env, va_list ap)
{
	int			i;

	i = 0L;
	env->flag_dz = 0;
	if (env->flag_hh == 1 && env->conv != 'D')
		a = (char)va_arg(ap, int);
	else if (env->flag_h == 1 && env->conv != 'D')
		a = (short)va_arg(ap, int);
	else if (env->flag_l == 1)
		a = va_arg(ap, long);
	else if (env->flag_ll == 1 || env->flag_j == 1 || env->flag_z == 1 ||
			env->conv == 'D')
		a = va_arg(ap, long long);
	else
		a = va_arg(ap, int);
	i += a;
	if (a == i && env->conv == 'D')
		env->flag_d = 1;
	ft_space_int(a, env);
	if (env->flag_ms == 0 && (a < 0 || (a >= 0 && env->flag_ps == 1)))
		env->nb_char++;
}

void			ft_useva(t_env *env, va_list ap)
{
	if (env->conv == 's' && env->flag_l == 0)
		flag_str(env, ap, 0, NULL);
	else if (env->conv == 'S' || (env->conv == 's' && env->flag_l == 1))
		flag_wstr(env, ap, 0, 0);
	else if (env->conv == 'p' || env->conv == 'x' || env->conv == 'X')
		flag_hexa(0, env, ap);
	else if (env->conv == 'd' || env->conv == 'D' || env->conv == 'i')
		flag_int(0, env, ap);
	else if (env->conv == 'o' || env->conv == 'O')
		flag_octal(0, env, ap);
	else if (env->conv == 'u' || env->conv == 'U')
		flag_unsigned(0, env, ap);
	else if (env->conv == 'c' && env->flag_l == 0)
		flag_char(env, ap);
	else if (env->conv == 'C' || (env->flag_l == 1 && env->conv == 'c'))
		flag_wchar(env, ap);
	else if (env->conv == '%')
		flag_pourcent(env);
	else
		flag_rien(env);
}
