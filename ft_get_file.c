/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:55:03 by quroulon          #+#    #+#             */
/*   Updated: 2016/10/09 20:36:32 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_file_empty_line(char **file)
{
	int			i;
	char		*tmp;

	i = 0;
	tmp = *file;
	while (tmp[i])
	{
		if (tmp[i] == '\n')
		{
			i++;
			if (tmp[i] && tmp[i] == '\n')
			{
				(*file) = ft_strsub(tmp, 0, i);
				ft_strdel(&tmp);
				break ;
			}
		}
		i++;
	}
}

void			ft_scd_part_file(char **tab, char **file, int i)
{
	int			j;
	int			cpt;
	char		*tmp;

	tmp = *file;
	while (tab[i])
	{
		cpt = 0;
		j = 0;
		if (tab[i][0] != '#')
		{
			while (tab[i][j])
			{
				if (tab[i][j] == '-')
					cpt++;
				j++;
			}
			if (cpt != 1)
				break ;
		}
		i++;
	}
	j = 0;
	while ((*file)[j])
	{
		if ((*file)[j] == '\n')
			i--;
		if (i == 0)
			break ;
		j++;
	}
	(*file) = ft_strsub(tmp, 0, j);
	ft_strdel(&tmp);
}

void			ft_sort_file(char **file, t_lem_in *env)
{
	int			i;
	int			j;
	int			cpt;
	char		**tab;

	i = 0;
	j = 0;
	tab = ft_strsplit(*file, '\n');
	while (tab[i])
	{
		cpt = 0;
		j = 0;
		while (tab[i][j] && tab[i][0] != '#')
		{
			if (tab[i][j] == ' ')
			{
				j++;
				if (ft_isdigit(tab[i][j]) == 0)
				{
					ft_printf("Le fichier est mal formaté, ligne %d", i + 1);
					ft_dbstrdel(tab);
					ft_error_lem_in("\0", env);
				}
				cpt++;
			}
			if (tab[i][j] == '-' && tab[i][0] != '#' && i != 0)
			{
				ft_scd_part_file(tab, file, i);
				ft_dbstrdel(tab);
				return ;
			}
			j++;
		}
		if (cpt != 2 && tab[i][0] != '#' && i != 0)
		{
			ft_dbstrdel(tab);
			ft_error_lem_in(NULL, env);
		}
		i++;
	}
	ft_dbstrdel(tab);
}

// void			ft_verif_begin(char *file, t_lem_in *env, int *verif)
// {
// 	int			i;
// 	int			j;

// 	i = 0;
// 	j = 0;
// 	(*verif)++;
// 	while (file[i] && file[i] != '\n')
// 	{
// 		if (file[i] == '#')
// 		{
// 			while (file[i] != EOF && file[i] != '\n')
// 				i++;
// 			if (file[i] == '\n')
// 				i++;
// 			else
// 				ft_error_lem_in(NULL, env);
// 		}
// 		else if (ft_isdigit(file[i]) == 1)
// 			i++;
// 		else if (file[i] == '\n')
// 			break ;
// 		else if (ft_isdigit(file[i]) == 0 && file[i] != '\n')
// 			ft_error_lem_in(NULL, env);
// 	}
// }

// void			ft_get_file(char **file, t_lem_in *env, int verif)
// {
// 	int			fd;
// 	char		*buf;
// 	char		*tmp;

// 	buf = ft_strnew(BUFF_READ);
// 	*file = ft_strnew(0);
// 	fd = 0;
// 	while (read(fd, buf, BUFF_READ) > 0)
// 	{
// 		tmp = *file;
// 		*file = ft_strjoin(tmp, buf);
// 		ft_strdel(&tmp);
// 		ft_strdel(&buf);
// 		if (verif == 0)
// 			ft_verif_begin(*file, env, &verif);
// 		else
// 			verif++;
// 		buf = ft_strnew(BUFF_READ);
// 	}
// 	ft_strdel(&buf);
// 	ft_file_empty_line(file);
// 	ft_sort_file(file, env);
// }

void			ft_thd_part(char *line, t_lem_in *env)
{
	if (line[0] == 'L')
		ft_error_lem_in_start(line, env);
}

void			ft_scd_part(char *line, t_lem_in *env)
{
	int			i;

	i = 0;
	if (line[0] == 'L')
		ft_error_lem_in_start(line, env);
	while (line[i])
	{
		if (line[i] == '-')
		{
			env->thd_part = 1;
			return ;
		}
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
	else if (env->thd_part == 1)
		ft_thd_part(line, env);
	else
		return (0);
	return (1);
}

void			ft_get_file(char **file, t_lem_in *env)
{
	int			i;
	char		*line;
	char		*tmp;

	i = 0;
	line = NULL;
	tmp = NULL;
	while (get_next_line(0, &line) > 0 && i == 0)
	{
		if (*file == NULL)
			*file = ft_strnew(0);
		if (ft_analyse(line, env) == 0)
			i = 1;
		tmp = *file;
		*file = ft_strjoin(tmp, line);
		ft_strdel(&tmp);
		ft_strdel(&line);
		tmp = *file;
		*file = ft_strjoin(tmp, "\n");
		ft_strdel(&tmp);
	}
	ft_strdel(&line);
}
