/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 20:42:29 by quroulon          #+#    #+#             */
/*   Updated: 2016/11/21 18:25:08 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_nb_ants(char *file, t_lem_in **env)
{
	int			i;

	i = 0;
	while (file[i] != '\0' && file[i] == '#')
	{
		i++;
		ft_hashtag(&i, file, *env);
		if ((*env)->t_start != 0 || (*env)->t_end != 0)
			ft_error_lem_in(CMD_BAD_PLACE, *env);
	}
	(*env)->nb_ant = ft_atoi(file + i);
	while (ft_isdigit(file[i]) == 1)
		i++;
	(*env)->tmp = i;
	if ((*env)->nb_ant <= 0)
		ft_error_lem_in(BAD_NB_ANT, *env);
}

void			ft_putsmall_solution(t_lem_in *env)
{
	int			num;

	num = 1;
	while (num - 1 != env->nb_ant)
	{
		ft_printf("L%d-%s\n", num, env->start->path->name);
		num++;
	}
}

static void		ft_init_env(t_lem_in *env)
{
	env->i = 0;
	env->tmp = 0;
	env->fst_part = 0;
	env->scd_part = 0;
	env->thd_part = 0;
	env->nb_ant = 0;
	env->nb_room = 0;
	env->tmp_coo1 = 0;
	env->tmp_coo2 = 0;
	env->nb_path = 0;
	env->t_start = 0;
	env->t_end = 0;
	env->file = NULL;
	env->tmp_name = NULL;
	env->fst_ant = NULL;
	env->scd_ant = NULL;
	env->room = NULL;
	env->start = NULL;
	env->end = NULL;
	env->hash = NULL;
}

int				main(void)
{
	t_lem_in	*env;

	env = (t_lem_in*)malloc(sizeof(t_lem_in));
	ft_init_env(env);
	ft_get_file(&env->file, env);
	ft_nb_ants(env->file, &env);
	(env->tmp)++;
	ft_check_path(&env, ft_check_room(env->file, &env, env->tmp));
	ft_resolution(env);
	ft_printf("%s\n", env->file);
	if (env->nb_path == 1)
		ft_putsmall_solution(env);
	else
		ft_put_solution(env, 1, 0, NULL);
	free_all(&env);
	free(env);
	return (0);
}
