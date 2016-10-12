/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 19:39:07 by quroulon          #+#    #+#             */
/*   Updated: 2016/10/12 18:28:42 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_hash(char *word, t_lem_in *env)
{
	int			cpt;
	int			hashAddress;

	hashAddress = 5381;
	cpt = 0;
	while (word[cpt] != '\0')
	{
	    hashAddress = ((hashAddress << 5) + hashAddress) + word[cpt];
		cpt++;
	}
	return (hashAddress % (int)(env->nb_room * 1.5));
}

// void			ft_hashtable_lem_in(t_lem_in *env)
// {

// }