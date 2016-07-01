/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_application.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 17:33:00 by quroulon          #+#    #+#             */
/*   Updated: 2016/06/03 17:03:40 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			flag_dz_str(t_env *env, char *str)
{
	if (env->flag_dz == 1 && env->conv == 'p')
	{
		(env->maj == 1) ? ft_putstr("0X") : ft_putstr("0x");
		env->nb_char += 2;
	}
	else if (env->flag_dz == 1 && ft_strcmp(str, "0") != 0 && env->conv != 'o'
			&& env->conv != 'O')
	{
		(env->maj == 1) ? ft_putstr("0X") : ft_putstr("0x");
		env->nb_char += 2;
	}
}

void			ft_putarg_wstr(t_env *e, wchar_t *str)
{
	int			i;
	int			surplus;

	i = 0;
	surplus = (e->flag_dz == 1) ? 2 : 0;
	if ((int)ft_wstrlen(str) + surplus < e->nb_sp)
	{
		surplus += e->nb_sp - (int)ft_wstrlen(str);
		while (i < surplus)
		{
			if (e->flag_pt != 0)
				(e->flag_zr == 1 && (e->nb_sp < e->flag_pt || e->nb_sp >
				ft_wstrlen(str))) ? ft_putchar('0') : ft_putchar(' ');
			else
				(e->flag_zr == 1) ? ft_putchar('0') : ft_putchar(' ');
			i++;
			e->nb_char++;
		}
	}
}

void			ft_putarg_str(t_env *e, char *s, int i, int surplus)
{
	if (e->conv == 'o' || e->conv == 'O')
		surplus -= (ft_strcmp(s, "0") == 0 && e->flag_pt == -1) ? 1 : 0;
	else
		surplus = (e->flag_dz == 1) ? 2 : 0;
	if (e->conv == 'o' || e->conv == 'x' || e->conv == 'O' || e->conv == 'X' ||
		e->conv == 'p')
		surplus += (e->flag_pt > 0 && e->flag_pt > (int)ft_strlen(s)) ?
					e->flag_pt - ft_strlen(s) : 0;
	if ((int)ft_strlen(s) + surplus < e->nb_sp)
	{
		while (i < (e->nb_sp - ((int)ft_strlen(s) + surplus)))
		{
			if (e->flag_pt != 0)
				(e->flag_zr == 1 && (e->nb_sp < e->flag_pt ||
				e->nb_sp > (int)ft_strlen(s)) && e->flag_pt != -1) ?
				ft_putchar('0') : ft_putchar(' ');
			else
				(e->flag_zr == 1) ? ft_putchar('0') : ft_putchar(' ');
			i++;
			e->nb_char++;
		}
	}
	e->nb_char += ft_strlen(s);
}

static void		ft_putarg_ll2(t_env *env, long long a, int i)
{
	if ((env->flag_ps == 1 || a < 0) && env->flag_pt > 0)
		(a < 0) ? ft_putchar('-') : ft_putchar('+');
	if (env->flag_ms == 0)
		while (i < (env->flag_pt - ft_nbrlen_ll(a)))
		{
			ft_putchar('0');
			i++;
			env->nb_char++;
		}
	if (((env->flag_ll == 1 || env->flag_l == 1 || env->flag_j == 1 ||
			env->flag_z == 1) && env->conv == 'u') || env->conv == 'U')
		env->nb_char += ft_nbrlen_ull(a);
	else if (env->flag_z == 1 && a < 0 && a > -2147483648)
		env->nb_char += ft_nbrlen_ui(a);
	else
		env->nb_char += ft_nbrlen_ll(a);
}

void			ft_putarg_ll(t_env *env, long long a)
{
	int			i;
	int			surplus;

	i = 0;
	surplus = (env->flag_dz == 1) ? 2 : 0;
	surplus += (a < 0 || (env->flag_ps == 1 && a >= 0)) ? 1 : 0;
	surplus += (env->flag_pt > 0 && env->flag_pt > ft_nbrlen_ll(a)) ?
				env->flag_pt - ft_nbrlen_ll(a) : 0;
	surplus += (env->flag_ps == -1) ? 1 : 0;
	surplus -= (a == 0 && env->flag_pt == -1) ? 1 : 0;
	if (ft_nbrlen_ll(a) + surplus < env->nb_sp)
		while (i < (env->nb_sp - (ft_nbrlen_ll(a) + surplus)))
		{
			if (env->flag_pt > 0)
				(env->flag_zr == 1 && env->nb_sp < (env->flag_pt - 1)) ?
					ft_putchar('0') : ft_putchar(' ');
			else
				(env->flag_zr == 1 && env->flag_pt != -1) ? ft_putchar('0') :
				ft_putchar(' ');
			i++;
			env->nb_char++;
		}
	ft_putarg_ll2(env, a, 0);
}
