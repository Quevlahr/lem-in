/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 20:21:50 by quroulon          #+#    #+#             */
/*   Updated: 2016/06/03 16:31:08 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_flag_ms_int(long long *a, t_env *env)
{
	int			i;

	i = 0;
	if (*a < 0 || env->flag_ps == 1)
	{
		(*a < 0) ? ft_putchar('-') : ft_putchar('+');
		(*a < 0) ? *a *= -1 : 0;
		env->flag_ps = -1;
		env->nb_char++;
	}
	while (i < (env->flag_pt - ft_nbrlen(*a)))
	{
		ft_putchar('0');
		i++;
		env->nb_char++;
	}
}

static void		ft_affichage_int(long long a, t_env *env)
{
	if (env->flag_pt != -1 || a != 0)
	{
		if (((env->flag_ll == 1 || env->flag_l == 1 || env->flag_j == 1 ||
			env->flag_z == 1) && env->conv == 'u') || env->conv == 'U')
			ft_putnbr_ull(a);
		else if ((env->conv == 'D' && env->flag_d == 0) &&
			a < 0 && a > -2147483648)
			ft_putnbr_ui(a);
		else
			ft_putnbr_ll(a);
	}
	else
		env->nb_char--;
}

static void		ft_space_int2(long long a, t_env *env)
{
	if (env->flag_ms == 1)
	{
		(env->flag_ps == 1 && a >= 0) ? ft_putchar('+') : 0;
		ft_affichage_int(a, env);
		ft_putarg_ll(env, a);
	}
	else
	{
		ft_putarg_ll(env, a);
		(env->flag_ps == 1 && a >= 0) ? ft_putchar('+') : 0;
		if (env->flag_pt != -1 || a != 0)
			ft_affichage_int(a, env);
		else
			env->nb_char--;
	}
}

void			ft_space_int(long long a, t_env *env)
{
	if (env->flag_ms == 1)
		ft_flag_ms_int(&a, env);
	if (env->flag_sp == 1 && env->flag_ps == 0 && a >= 0)
	{
		ft_putchar(' ');
		env->nb_char++;
		(env->nb_sp > 0) ? env->nb_sp-- : 0;
	}
	if ((env->flag_ps == 1 || a < 0) && env->flag_pt > 0)
	{
		ft_putarg_ll(env, a);
		a *= (a < 0) ? -1 : 1;
		ft_affichage_int(a, env);
	}
	else if (env->flag_zr == 1 && (env->flag_ps == 1 || a < 0))
	{
		(a < 0) ? ft_putchar('-') : ft_putchar('+');
		ft_putarg_ll(env, a);
		(a < 0) ? a *= -1 : 0;
		ft_affichage_int(a, env);
	}
	else
		ft_space_int2(a, env);
}
