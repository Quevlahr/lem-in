/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_list_octal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 16:08:03 by quroulon          #+#    #+#             */
/*   Updated: 2016/06/03 16:33:55 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			flag_octal2(long long a, t_env *env, char **str)
{
	if (env->flag_hh == 1 && env->conv != 'O')
		*str = ft_itoabase_uc(a, 8, 0);
	else if (env->flag_h == 1 && env->conv != 'O')
		*str = ft_itoabase_us(a, 8, 0);
	else if (env->conv == 'O' && a > -2147483648 && a < 0)
		*str = ft_itoabase_ui(a, 8, 0);
	else if (env->flag_l == 0 && env->flag_ll == 0 && env->flag_j == 0 &&
			env->flag_z == 0 && env->conv == 'o')
		*str = ft_itoabase_ui(a, 8, 0);
	else
		*str = ft_itoabase_ull(a, 8, 0);
	if (env->flag_pt > 0 && ft_strcmp(*str, "0") == 0)
	{
		env->flag_dz = 0;
		ft_strdel(str);
		*str = ft_strnew(0);
	}
	if (env->flag_dz == 1 && env->flag_pt <= 0)
	{
		if (ft_strcmp(*str, "0") != 0)
			env->flag_pt = 1 + ft_strlen(*str);
		else
			env->flag_pt = 1;
	}
}

void			flag_octal(long long a, t_env *env, va_list ap)
{
	char		*str;

	str = NULL;
	env->flag_sp = 0;
	if (env->flag_l == 1 || env->conv == 'O')
		a = va_arg(ap, long);
	else if (env->flag_ll == 1)
		a = va_arg(ap, long long);
	else
		a = va_arg(ap, int);
	flag_octal2(a, env, &str);
	ft_space_str(str, env);
	ft_strdel(&str);
}
