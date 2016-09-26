/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_solution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:50:06 by quroulon          #+#    #+#             */
/*   Updated: 2016/09/26 13:19:31 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_put_solution(t_lem_in *env)
{
	int			num;
	t_room		*tmp;

	num = 0;
	while (env->end->ant != env->nb_ant)
	{
		tmp = env->start;
		ft_printf("tmp ant : %d\n", tmp->ant);
		if (env->start->ant > 0)
		{
			tmp->ant--;
			tmp = tmp->path;
			while (tmp->ant != 0)
			{
				tmp->ant++;
				ft_printf("L%d-%s ", tmp->ant, tmp->name);
				tmp = tmp->path;
				num++;
			}
			tmp->ant++;

		}
		else if (env->start->ant == 0)
		{
			while (tmp->ant == 0)
				tmp = tmp->path;
		}
		ft_printf("\n");
		// tmp = env->start->path;
		// if (tmp->ant == 0 && env->start->ant > 0)
		// {
		// 	env->start->ant--;
		// 	tmp->ant++;
		// }
		// else
		// {
		// 	while (tmp->ant != 0)
		// 	{

		// 		tmp = tmp->path;
		// 	}
		// }
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