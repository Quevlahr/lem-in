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
	int			hash_address;

	hash_address = 5381;
	cpt = 0;
	while (word[cpt] != '\0')
	{
		hash_address = ((hash_address << 5) + hash_address) + word[cpt];
		cpt++;
	}
	return (hash_address % (int)(env->nb_room * 1.5));
}
