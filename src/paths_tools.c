/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 13:02:40 by abouvero          #+#    #+#             */
/*   Updated: 2018/05/02 13:03:20 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

t_path			*last(t_path *path)
{
	while (path->next)
		path = path->next;
	return (path);
}

t_room_list		*get_min_addr(t_room_links *links)
{
	int			min;
	t_room_list	*room;

	min = INTMAX;
	room = NULL;
	while (links)
	{
		if (links->room->weight != -1 && !links->room->traffic
			&& links->room->weight < min)
		{
			min = links->room->weight;
			room = links->room;
		}
		links = links->next;
	}
	return (room);
}

int				get_min(t_room_links *rl)
{
	int 	min;

	min = INTMAX;
	while (rl)
	{
		if (rl->room->weight != -1 && !rl->room->traffic)
			min = rl->room->weight < min ? rl->room->weight : min;
		rl = rl->next;
	}
	return (min == INTMAX ? -1 : min + 1);
}

int				initialized(t_room_links *links)
{
	while (links)
	{
		if (links->room->weight != -1 && !links->room->traffic)
			return (1);
		links = links->next;
	}
	return (0);
}

void			restart_weight(t_room_list *rl)
{
	while (rl)
	{
			rl->weight = rl->type == END ? 0 : -1;
			rl = rl->next;
	}
}
