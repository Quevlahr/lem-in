/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 20:09:47 by quroulon          #+#    #+#             */
/*   Updated: 2016/06/03 16:31:15 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_flag_pt_str(char *str, t_env *env)
{
	if (env->flag_pt != -1 || ft_strcmp(str, "0") != 0)
		ft_putstr(str);
	else
		env->nb_char--;
}

static void		ft_space_str2(char *str, t_env *env)
{
	if (env->flag_dz == 1 && env->flag_zr == 0)
	{
		ft_putarg_str(env, str, 0, 0);
		flag_dz_str(env, str);
		flag_pt_xo(env, str);
		ft_flag_pt_str(str, env);
	}
	else if (env->flag_ms == 0 && env->nb_sp > env->flag_pt &&
			env->flag_pt != 0)
	{
		ft_putarg_str(env, str, 0, 0);
		flag_pt_xo(env, str);
		flag_dz_str(env, str);
		ft_flag_pt_str(str, env);
	}
	else
	{
		flag_dz_str(env, str);
		flag_pt_xo(env, str);
		ft_putarg_str(env, str, 0, 0);
		ft_flag_pt_str(str, env);
	}
}

void			ft_space_str(char *str, t_env *env)
{
	if (env->flag_sp == 1)
	{
		ft_putchar(' ');
		env->nb_char++;
		(env->nb_sp > 0) ? env->nb_sp-- : 0;
	}
	if (env->flag_ms == 1)
	{
		flag_dz_str(env, str);
		flag_pt_xo(env, str);
		ft_flag_pt_str(str, env);
		ft_putarg_str(env, str, 0, 0);
	}
	else
		ft_space_str2(str, env);
}
