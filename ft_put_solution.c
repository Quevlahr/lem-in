/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_solution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:50:06 by quroulon          #+#    #+#             */
/*   Updated: 2016/09/21 18:48:23 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char			**ft_init_tabpath(t_lem_in *env, char **tab, int i, int *len)
{
	env->room = env->start;
	while (env->room->path)
	{
		(*len)++;
		env->room = env->room->path;
	}
	tab = (char**)malloc(sizeof(char*) * (*len));
	while (i < (*len))
		tab[i++] = NULL;
	i = 0;
	env->room = env->start;
	env->room = env->room->path;
	while (env->room)
	{
		tab[i++] = ft_strdup(env->room->name);
		if (env->room->path == NULL)
			break ;
		env->room = env->room->path;
	}


	// int i = 0;
	// while (tab[i])
	// {
	// 	ft_printf("%s\n", tab[i++]);
	// }

	return (tab);
}

void			ft_put_solution(t_lem_in *env, int frm_d, int frm_a, int frm_p)
{
	int			total;
	int			i;
	int			len;
	char		**tab;
	int			tmp;
	int			num;

	tab = NULL;
	len = 0;
	tmp = 0;
	num = 0;
	tab = ft_init_tabpath(env, tab, 0, &len);

	total = env->nb_ant;
	while (frm_a != env->nb_ant)
	{
		i = 0;
		num = frm_a;
		if (frm_p < env->nb_ant)
			frm_p += env->nb_path;
		if (frm_a == 0)
			i++;
		while (i < frm_p && i > 0)
		{
			i++;
			num++;
			// ft_printf("\n%d, %d\n", frm_a, frm_d);
			if (tab[frm_p - i - 1] && frm_a > 1)
			{
				ft_printf("L%d-%s ", num, tab[frm_p - i - 1]);
				ft_printf("    p : %d, a : %d, d : %d, m : %d\n", frm_p, frm_a, frm_d, frm_p - frm_a - i);

			}
			else if (tab[frm_p - frm_a - i])
			{
				ft_printf("L%d-%s ", num, tab[frm_p - frm_a - i]);
				ft_printf("    p : %d, a : %d, d : %d, m : %d\n", frm_p, frm_a, frm_d, frm_p - frm_a - i);
			}
			if (frm_p - frm_a - i + 1 == len && frm_a < env->nb_ant)
				tmp++;
		}
		while (tmp > 0)
		{
			frm_a++;
			tmp--;
		}
		// if (frm_p - frm_a - i + 1 == len && frm_a < env->nb_ant)
		// {
		// 	frm_p--;
		// }
		if (frm_d > 0)
			frm_d--;
		ft_printf("    p : %d, a : %d, d : %d, m : %d\n", frm_p, frm_a, frm_d, frm_p - frm_a - i);

		// ft_printf("\n");
	}

	// while (frm >= 0)
	// {
	// 	// total = env->nb_ant;
	// 	env->room = env->start;
	// 	env->room = env->room->path;
	// 	total = env->nb_ant - frm;
	// 	while (total - frm > 0 && env->room)
	// 	{
	// 		ft_printf("L%d-%s ", total - frm, env->room->name);
	// 		if (env->room->path == NULL)
	// 			break ;
	// 		env->room = env->room->path;
	// 		total++;
	// 	}
	// 	ft_printf("\n");
	// 	frm--;
	// }



	// while (frm >= 0)
	// {
	// 	total = env->nb_ant;
	// 	env->room = env->start;
	// 	env->room = env->room->path;
	// 	while (total - frm > 0 && env->room)
	// 	{
	// 		ft_printf("L%d-%s ", total - frm, env->room->name);
	// 		if (env->room->path == NULL)
	// 			break ;
	// 		env->room = env->room->path;
	// 		total--;
	// 	}
	// 	ft_printf("\n");
	// 	frm--;
	// }

}