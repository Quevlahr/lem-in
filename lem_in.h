/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 20:40:54 by quroulon          #+#    #+#             */
/*   Updated: 2016/11/02 15:45:12 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define BUFF_READ 2000
# define CMD_BAD_PLACE "Les commandes start et end sont mal placées"
# define BAD_NB_ANT "Le nombre de fourmi n'est pas correct"
# define BAD_ROOM_NAME "Une salle ne peut commencer par L"
# define SPACE_NEED_COO "Il faut un espace entre les coordonnées"
# define COO_NUM "Les coordonnées doivent etre des nombres"
# define DOUBLE_CMD "Il ne peut n'y avoir qu'une salle start ou end"
# define NO_START "Il n'y a pas de salle start"
# define NO_END "Il n'y pas de salle end"

# include "fcntl.h"
# include "libft/libft.h"

typedef struct		s_room
{
	char			*name;
	int				coo1;
	int				coo2;
	int				id;
	int				pass;
	int				pass2;
	int				ant;
	int				dead_end;
	int				nb_doors;
	int				pds;
	struct s_ant	*h_ant;
	struct s_room	*next;
	struct s_room	*begin;
	struct s_room	*path;
	struct s_room	*tmp_path;
	struct s_room	*nxt_hash;
	struct s_room	**doors;
}					t_room;

typedef struct		s_ant
{
	int				num;
	t_room			*room;
}					t_ant;

typedef struct		s_lem_in
{
	int				tmp;
	int				i;
	int				fst_part;
	int				scd_part;
	int				thd_part;
	int				nb_ant;
	int				nb_room;
	int				tmp_coo1;
	int				tmp_coo2;
	int				nb_path;
	char			*tmp_name;
	t_room			*room;
	char			*file;
	int				t_start;
	int				t_end;
	t_room			*start;
	t_room			*end;
	t_room			**hash;
}					t_lem_in;

void				ft_error_lem_in(char *str, t_lem_in *env);
void				ft_error_lem_in_start(char *msg, char *str, t_lem_in *env);
void				ft_put_lem_in(t_lem_in *env);
void				free_all(t_lem_in **env);

int					ft_check_room(char *file, t_lem_in **env, int i);

int					ft_hashtag(int *i, char *file, t_lem_in *env);

int					ft_change_file(t_lem_in *env, char **str, int i);
t_room				*ft_found_hash(t_lem_in *env, char *str);

int					ft_check_path(t_lem_in **env, int i);

int					ft_len_room(t_room *room);
void				ft_push_room(t_lem_in *env);

int					ft_resolution(t_lem_in *env);

void				ft_put_solution(t_lem_in *env);
void				ft_put_hashtable(t_lem_in *env);
void				ft_get_file(char **file, t_lem_in *env);

int					ft_hash(char *word, t_lem_in *env);

#endif
