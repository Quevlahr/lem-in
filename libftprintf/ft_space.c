/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 15:24:40 by quroulon          #+#    #+#             */
/*   Updated: 2016/06/03 16:31:00 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static UI		ft_givebit(UI pos, UI n)
{
	return (((1 << pos) & n) >> pos);
}

static int		ft_replacebit(UI *bit, int a, int cpt, t_env *env)
{
	int			i;
	int			seis;

	seis = 0;
	while (cpt - 6 * seis > 0)
	{
		i = (cpt - 6 * seis < 6) ? cpt - 6 * seis : 6;
		(bit[0] == 0) ? i = 7 : 0;
		while (i > 0)
		{
			bit[seis] = bit[seis] << 1;
			bit[seis] = bit[seis] ^ ft_givebit((i - 1) + 6 * seis, a);
			i--;
		}
		env->nb_char++;
		seis++;
	}
	return (seis);
}

static UI		*ft_initbit(int a, t_env *env, UI *bit)
{
	bit = (UI*)malloc(sizeof(int) * 4);
	bit[0] = 2;
	bit[1] = 2;
	bit[2] = 2;
	bit[3] = 2;
	if (a < 128)
	{
		ft_putchar(a);
		env->nb_char++;
	}
	return (bit);
}

void			ft_space_wchar(int a, t_env *env, int seis, UI *bit)
{
	bit = ft_initbit(a, env, bit);
	if ((a > 55296 && a < 65536) || a > 1114111 || a < 0)
		env->nb_char = -1;
	else
	{
		if (a < 2048 && a > 128)
		{
			bit[1] = 6;
			seis = ft_replacebit(bit, a, 11, env);
		}
		else if (a < 65536 && a > 2048)
		{
			bit[2] = 14;
			seis = ft_replacebit(bit, a, 16, env);
		}
		else if (a < 2097152 && a > 65536)
		{
			bit[3] = 30;
			seis = ft_replacebit(bit, a, 21, env);
		}
		while (seis > 0)
			ft_putchar(bit[--seis]);
	}
	free(bit);
}

void			ft_space_char(char c, t_env *env)
{
	int			i;

	i = 0;
	if (env->flag_ms == 1)
	{
		ft_putchar(c);
		while (i < env->nb_sp - 1)
		{
			(env->flag_zr == 1) ? ft_putchar('0') : ft_putchar(' ');
			i++;
			env->nb_char++;
		}
	}
	else
	{
		while (i < env->nb_sp - 1)
		{
			(env->flag_zr == 1) ? ft_putchar('0') : ft_putchar(' ');
			i++;
			env->nb_char++;
		}
		ft_putchar(c);
	}
	env->nb_char++;
}
