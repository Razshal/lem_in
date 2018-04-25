/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:13:11 by abouvero          #+#    #+#             */
/*   Updated: 2018/04/25 13:13:14 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

t_path 		*last(t_path *path)
{
	while (path->next)
		path = path->next;
	return (path);
}

t_room_list *get_min_addr(t_room_links *links)
{
	int 	min;
	t_room_list *room;

	min = INTMAX;
	room = NULL;
	while (links)
	{
		if (links->room->weight != -1 && !links->room->traffic && links->room->weight < min)
		{
			min = links->room->weight;
			room = links->room;
		}
		links = links->next;
	}
	return (room);
}

int 	get_min(t_room_links *rl)
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

int 	initialized(t_room_links *links)
{
	while (links)
	{
		if (links->room->weight != -1)
			return (1);
		links = links->next;
	}
	return (0);
}

void 	restart_weight(t_room_list *rl)
{
	while (rl)
	{
		rl->weight = rl->type == END ? 0 : -1;
		rl = rl->next;
	}
}

int		init_weight(t_room_list *rl)
{
	t_room_list *beg;

	beg = rl;
	restart_weight(rl);
	while (rl)
	{
		if (rl->weight == -1 && initialized(rl->l_rooms) && rl->type != START)
		{
			if ((rl->weight = get_min(rl->l_rooms)) == -1)
				return (1);
			rl = beg;
		}
		rl = rl->next;
	}
	return (0);
}

t_path	*add_path(t_path *path, t_room_list *room)
{
	t_path	*new;
    t_path  *beg;

	if (!(new = (t_path*)malloc(sizeof(t_path))))
		return (NULL);
	new->next = NULL;
	new->room = room;
	new->length = 0;
    beg = path;
	if (!path)
		return (new);
	while (path->next)
		path = path->next;
	path->next = new;
	return (beg);
}

t_path 	*solve_path(t_room_list *rl, t_path *path)
{
	t_room_links *links;
	t_room_list	 *room;

	path = add_path(path, rl);
	while (last(path)->room->type != END)
	{
		links = last(path)->room->l_rooms;
		if ((room = get_min_addr(links)))
			path = add_path(path, room);
		else
			return (NULL);
	}
	return (path);
}

t_room_list	*get_start(t_room_list *rl)
{
	while (rl)
	{
		if (rl->type == START)
			return (rl);
		rl = rl->next;
	}
	return (NULL);
}

t_path	*apply_traffic(t_path *path)
{
	t_path	*beg;

	beg = path;
	while (path)
	{
		path->room->traffic = path->room->type == END ? 0 : 1;
		path = path->next;
	}
	return (beg);
}

int		ft_list_size_path(t_path *path)
{
	return (!path ? 0 : 1 + ft_list_size_path(path->next));
}

t_path	*get_path(t_room_list *rl)
{
	t_path *path;

	if (init_weight(rl))
		return (NULL);
	if (!(path = solve_path(get_start(rl), NULL)))
		return (NULL);
	path->length = ft_list_size_path(path);
	return (apply_traffic(path));
}
