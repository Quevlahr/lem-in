/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 15:48:29 by quroulon          #+#    #+#             */
/*   Updated: 2016/06/03 16:30:21 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_initenv(t_env *env)
{
	env->flag_dz = 0;
	env->flag_zr = 0;
	env->flag_ms = 0;
	env->flag_ps = 0;
	env->flag_sp = 0;
	env->flag_l = 0;
	env->flag_ll = 0;
	env->flag_h = 0;
	env->flag_hh = 0;
	env->flag_j = 0;
	env->flag_z = 0;
	env->flag_pt = 0;
	env->flag_d = 0;
	env->nb_sp = 0;
	env->maj = 0;
	env->conv = '\0';
}

int				ft_verifchar(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'u' || c == 'U' || c == 'x' ||
		c == 'd' || c == 'D' || c == 'i' || c == 'o' || c == 'O' || c == '%' ||
		c == 'X' || c == 'c' || c == 'C')
		return (1);
	else if (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ' ||
		c == '.' || c == 'l' || c == 'l' || c == 'j' || c == 'h' || c == 'h' ||
		c == 'z')
		return (2);
	return (0);
}

void			ft_initdigit(t_env *env, int *i)
{
	env->nb_sp = ft_atoi((env->str) + *i);
	if (env->nb_sp != 0)
		(*i) += ft_nbrlen(env->nb_sp);
}

int				ft_verifbase(t_env *env, int *i)
{
	int			tmp;

	tmp = 0;
	(env->str[*i] == '#') ? env->flag_dz = 1 : tmp++;
	(env->str[*i] == '0') ? env->flag_zr = 1 : tmp++;
	(env->str[*i] == '-') ? env->flag_ms = 1 : tmp++;
	(env->str[*i] == '+') ? env->flag_ps = 1 : tmp++;
	(env->str[*i] == ' ') ? env->flag_sp = 1 : tmp++;
	(env->str[*i] == 'j') ? env->flag_j = 1 : tmp++;
	(env->str[*i] == 'z') ? env->flag_z = 1 : tmp++;
	(tmp < 7) ? (*i)++ : 0;
	return (tmp < 7 ? 0 : 1);
}

void			ft_veriflh(t_env *e, int *i, int *l, int *h)
{
	if (e->str[*i] == 'l' && *l == 0 && (*i)++)
	{
		e->flag_ll = 0;
		e->flag_l = 1;
		*l = 1;
	}
	else if (e->str[*i] == 'l' && *l == 1 && (*i)++)
	{
		e->flag_ll = 1;
		e->flag_l = 0;
		*l = 0;
	}
	else if (e->str[*i] == 'h' && *h == 0 && (*i)++)
	{
		e->flag_ll = 0;
		e->flag_h = 1;
		*h = 1;
	}
	else if (e->str[*i] == 'h' && *h == 1 && (*i)++)
	{
		e->flag_hh = 1;
		e->flag_h = 0;
		*h = 0;
	}
}
