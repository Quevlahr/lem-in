/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_list2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 15:52:34 by quroulon          #+#    #+#             */
/*   Updated: 2016/06/03 16:33:04 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			flag_rien(t_env *env)
{
	env->nb_sp--;
	env->nb_char++;
	(env->flag_ms == 1) ? ft_putchar(env->conv) : 0;
	while (env->nb_sp > 0)
	{
		(env->flag_zr == 1) ? ft_putchar('0') : ft_putchar(' ');
		env->nb_sp--;
		env->nb_char++;
	}
	(env->flag_ms == 0) ? ft_putchar(env->conv) : 0;
}

void			flag_pourcent(t_env *env)
{
	char		*c;

	c = ft_strnew(1);
	c[0] = '%';
	env->flag_sp = 0;
	env->flag_dz = 0;
	env->flag_pt = 0;
	ft_space_str(c, env);
	ft_strdel(&c);
}

void			flag_wchar(t_env *env, va_list ap)
{
	int			a;

	a = 0;
	a = va_arg(ap, int);
	ft_space_wchar(a, env, 0, NULL);
}

void			flag_char(t_env *env, va_list ap)
{
	char		c;

	env->flag_sp = 0;
	env->flag_dz = 0;
	if (env->flag_l == 1)
		flag_wchar(env, ap);
	else
	{
		c = va_arg(ap, int);
		ft_space_char(c, env);
	}
}

void			flag_unsigned(unsigned long long a, t_env *env, va_list ap)
{
	env->flag_ps = 0;
	env->flag_dz = 0;
	env->flag_sp = 0;
	if (env->flag_hh == 1 && env->conv != 'U')
		a = (unsigned char)va_arg(ap, unsigned int);
	else if (env->flag_h == 1 && env->conv != 'U')
		a = (unsigned short)va_arg(ap, unsigned int);
	else if (env->flag_l == 1 || env->conv == 'U')
		a = va_arg(ap, unsigned long);
	else if (env->flag_ll == 1 || env->flag_j == 1 || env->flag_z == 1)
		a = va_arg(ap, unsigned long long);
	else
		a = va_arg(ap, unsigned int);
	ft_space_int(a, env);
	if (env->flag_ms == 0 && env->flag_ps == 1)
		env->nb_char++;
}
