/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:55:03 by quroulon          #+#    #+#             */
/*   Updated: 2016/10/14 12:52:24 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_thd_part(char *line)
{
	int			i;

	i = 0;
	if (line[0] == 'L')
		return (0);
	while (line[i])
	{
		if (line[i] == '-' && i++)
			if (line[i] == 'L' || line[i] == '#')
				return (0);
		if (line[i] == ' ')
			return (0);
		i++;
	}
	return (1);
}

void			ft_scd_part(char *line, t_lem_in *env)
{
	int			i;

	i = 0;
	if (line[0] == 'L')
		ft_error_lem_in_start(line, env);
	while (line[i])
	{
		if (line[i] == '-' && (env->thd_part = 1))
			return ;
		if (line[i] == ' ')
		{
			i++;
			while (ft_isdigit(line[i]) == 1)
				i++;
			if (line[i++] != ' ')
				ft_error_lem_in_start(line, env);
			while (ft_isdigit(line[i]) == 1)
				i++;
			if (line[i] != '\0')
				ft_error_lem_in_start(line, env);
			env->nb_room++;
			return ;
		}
		i++;
	}
	ft_error_lem_in_start(line, env);
}

void			ft_fst_part(char *line, t_lem_in *env)
{
	int			i;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i++]) == 0)
			ft_error_lem_in_start(line, env);
	}
	env->fst_part = 1;
	env->scd_part = 1;
}

int				ft_analyse(char *line, t_lem_in *env)
{
	if (line[0] == '\0' && env->thd_part == 0)
		ft_error_lem_in_start(line, env);
	else if (line[0] == '\0' && env->thd_part == 1)
		return (0);
	if (line[0] == '#')
		 return (1);
	if (env->fst_part == 0)
		ft_fst_part(line, env);	
	else if (env->scd_part == 1 && env->thd_part == 0)
		ft_scd_part(line, env);
	if (env->thd_part == 1)
		if (ft_thd_part(line) == 0)
			return (0);
	return (1);
}

void			ft_get_file(char **file, t_lem_in *env)
{
	char		*line;
	char		*tmp;

	line = NULL;
	tmp = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (*file == NULL)
			*file = ft_strnew(0);
		if (ft_analyse(line, env) == 0)
			break ;
		else
		{
			tmp = *file;
			*file = ft_strjoin(tmp, line);
			ft_strdel(&tmp);
			tmp = *file;
			*file = ft_strjoin(tmp, "\n");
			ft_strdel(&tmp);
			ft_strdel(&line);
		}
	}
	ft_strdel(&tmp);
	ft_strdel(&line);
}


















