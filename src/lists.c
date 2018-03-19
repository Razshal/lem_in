/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 13:13:51 by mfonteni          #+#    #+#             */
/*   Updated: 2018/03/19 18:23:20 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

t_room_list *new_room(char *room_name, int room_type)
{
	t_room_list *rlist;
	BUGERROR;
	if (!(rlist = (t_room_list*)malloc(sizeof(t_room_list) * 1)))
		return (NULL);
	rlist->name = room_name;
	rlist->type = room_type;
	rlist->l_rooms = NULL;
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

int	add_room(char *room_name, int roomtype, t_room_list *rlist)
{
	t_room_list *rlist_local;

	if (!rlist && !(rlist = new_room(room_name, roomtype)) && !printf("test"))
		return (0);
	if (!get_room(room_name, rlist))
	{
		rlist_local = (new_room(room_name, roomtype)->next = rlist);
		rlist = rlist_local;
	}
	if (get_room(room_name, rlist)->type == CLASSICROOM
			&& roomtype != CLASSICROOM)
		get_room(room_name, rlist)->type = roomtype;
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
	char			**rooms;
	char			*room1;
	char			*room2;
	t_room_links	*links;

	if (!(ft_count_words(line, '-') == 2))
		return (0);
	rooms = ft_strsplit(line, '-');
	room1 = rooms[0];
	room2 = rooms[1];
	links = get_room(room1, rlist)->l_rooms;
	if (!add_lroom(new_room_link(get_room(room2, rlist)), links))
		return (0);
	if (!add_lroom(new_room_link(get_room(room1, rlist)), links))
		return (0);
	return (1);
}
