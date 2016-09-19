/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 20:40:54 by quroulon          #+#    #+#             */
/*   Updated: 2016/09/19 11:34:48 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define BUFF_READ 2000

# include "fcntl.h"
# include "libft/libft.h"

typedef struct		s_room
{
	char			*name;
	int				coo1;
	int				coo2;
	int				id;
	int				pass;
	struct s_room	*next;
	struct s_room	*begin;
	struct s_room	**doors;
}					t_room;

typedef struct		s_lem_in
{
	int				tmp;
	int				nb_ant;
	int				nb_room;
	int				tmp_coo1;
	int				tmp_coo2;
	char			*tmp_name;
	t_room			*room;
	char			*file;
	int				t_start;
	int				t_end;
	t_room			*start;
	t_room			*end;
}					t_lem_in;

void				ft_error_lem_in(char *str);
void				ft_push_room(t_lem_in *env);
int					ft_len_room(t_room *room);
int					ft_check_room(char *file, t_lem_in **env);
int					ft_hashtag(int j, int *i, char *file, t_lem_in *env);
int					ft_solve(t_room *start, t_room *end);

void				ft_put_lem_in(t_lem_in *env);

// t_room				*ft_new_room(char *name);

#endif
