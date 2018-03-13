/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 13:13:51 by mfonteni          #+#    #+#             */
/*   Updated: 2018/03/13 16:52:53 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

t_room_list *new_room(int room_number, int room_type)
{
	t_room_list *rlist;

	if (!(rlist = (t_room_list*)malloc(sizeof(t_room_list) * 1)))
		return (NULL);
	rlist->room_num = room_number;
	rlist->room_type = room_type;
	rlist->linked_rooms = NULL;
	rlist->next = NULL;
	return (rlist);
}

t_room_links *new_room_link(t_room_list *room)
{
	t_room_links *rlink;

	if (!(rlink = (t_room_links*)malloc(sizeof(t_room_links) * 1)))
		return (NULL);
	rlink->room = room;
	rlink->next = NULL;
	return (rlink);
}

int	add_room(int room_number, int roomtype, t_room_list *rlist)
{
	t_room_list *rlist_local;

	if (!rlist && !(rlist = new_room(room_number, roomtype)))
		return (0);
	if (!get_room(room_number, rlist))
	{
		rlist_local = (new_room(room_number, roomtype)->next = rlist);
		rlist = rlist_local;
	}
	if (get_room(room_number, rlist)->room_type == CLASSICROOM
			&& roomtype != CLASSICROOM)
		get_room(room_number, rlist)->room_type = roomtype;
	return (1);
}

static int	add_lroom(t_room_links *new, t_room_links *old)
{
	if (!new)
		return (0);
	new->next = old;
	old = new;
	return (1);
}

int			add_link(char *line, t_room_list *rlist)
{
	int				room1;
	int				room2;
	t_room_links	*links;

	room1 = ft_atoi(line);
	room2 = ft_atoi(&line[2]);
	add_room(room1, CLASSICROOM, rlist);
	add_room(room2, CLASSICROOM, rlist);
	links = get_room(room1, rlist)->linked_rooms;
	if (!get_lroom_num(room1, room2, rlist)
			&& !add_lroom(new_room_link(get_room(room2, rlist)), links))
		return (0);
	if (!get_lroom_num(room2, room1, rlist)
			&& !add_lroom(new_room_link(get_room(room1, rlist)), links))
		return (0);
	return (1);
}
