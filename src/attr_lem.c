/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:24:02 by abouvero          #+#    #+#             */
/*   Updated: 2018/04/16 12:25:01 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

//Changer l'init de lem list (ajouter /int arrived = 0/ et /t_path * = NULL/)

int 	all_arrived(t_lem_list *lem)
{
	while (lem)
	{
		if (!lem->arrived)
			return (0);
		lem = lem->next;
	}
	return (1);
}

void	moove_lems(t_lem_list *lem, t_path *path, t_room_list *rl)
{
	t_lem_list *beg;

	beg = lem;
	while (lem)
	{
		lem->path = solver(rl);
		lem = lem->next;
	}
	while (!all_arrived(lem))
	{
		lem = beg;
		while (lem)
		{
			if (!lem->path->occupied)
			{
				ft_printf("L%d-%s ", lem->lem, lem->path->room->name);
				lem->path->occupied = 0;
				if (!lem->path->next)
					lem->arrived = 1;
				else
				{
					lem->path = lem->path->next;
					lem->path->occupied = 1;
				}
			}
			lem = lem->next;
		}
		ft_printf("\n");
	}
}