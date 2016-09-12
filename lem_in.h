/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 20:40:54 by quroulon          #+#    #+#             */
/*   Updated: 2016/09/12 16:05:25 by quroulon         ###   ########.fr       */
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
	struct s_room	*next;
	struct s_room	*begin;
}					t_room;

typedef struct		s_lem_in
{
	int				nb_ant;
	int				tmp_coo1;
	int				tmp_coo2;
	char			*tmp_name;
	t_room			*room;
}					t_lem_in;

void				ft_error_lem_in(char *str);
void				ft_push_room(t_lem_in *env);

// t_room				*ft_new_room(char *name);

#endif
