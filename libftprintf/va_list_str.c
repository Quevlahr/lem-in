/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_list_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 16:11:09 by quroulon          #+#    #+#             */
/*   Updated: 2016/06/03 16:34:30 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		flag_str2(t_env *env, char *a, char *tmp)
{
	if (env->flag_pt > 0)
	{
		tmp = ft_modifstr(a, env);
		ft_space_str(tmp, env);
		ft_strdel(&tmp);
	}
	else
		ft_space_str(a, env);
}

void			flag_str(t_env *env, va_list ap, int nul, char *tmp)
{
	char		*a;

	env->flag_dz = 0;
	env->flag_sp = 0;
	a = va_arg(ap, char *);
	if (a == NULL && env->flag_pt != -1 && ++nul)
		ft_null_str(&a);
	if (env->flag_pt == -1)
	{
		while (env->nb_sp > 0)
		{
			(env->flag_zr == 1) ? ft_putchar('0') : ft_putchar(' ');
			env->nb_sp--;
			env->nb_char++;
		}
	}
	else
		flag_str2(env, a, tmp);
	if (nul > 0)
		ft_strdel(&a);
}

void			flag_wstr(t_env *env, va_list ap, int nul, int i)
{
	wchar_t		*a;

	a = (wchar_t *)va_arg(ap, char *);
	if (a == NULL && ++nul)
		ft_null_wstr(&a);
	if (env->flag_pt == -1)
		while (env->nb_sp > 0 && env->nb_sp--)
		{
			(env->flag_zr == 1) ? ft_putchar('0') : ft_putchar(' ');
			env->nb_char++;
		}
	else
	{
		if (env->flag_pt > 0)
			a = ft_modifwstr(a, env, 0, 0);
		(env->flag_ms == 0) ? ft_putarg_wstr(env, a) : 0;
		while (a[i])
			ft_space_wchar(a[i++], env, 0, NULL);
		(env->flag_ms == 1 && env->nb_char > 0) ? ft_putarg_wstr(env, a) : 0;
	}
	if (nul > 0)
	{
		free(a);
		a = NULL;
	}
}
