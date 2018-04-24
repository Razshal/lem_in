/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 13:13:51 by mfonteni          #+#    #+#             */
/*   Updated: 2018/04/16 17:09:46 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

t_room_list			*new_room(char *room_name, int room_type)
{
	t_room_list *rlist;

	if (!(rlist = (t_room_list*)malloc(sizeof(t_room_list) * 1)))
		return (NULL);
	rlist->name = room_name;
	rlist->type = room_type;
	rlist->occupied = 0;
	rlist->number_of_links = 0;
	rlist->l_rooms = NULL;
	rlist->next = NULL;
	return (rlist);
}

static t_room_links	*new_room_link(char *room_name, t_recurse *infos)
{
	t_room_links *rlink;
	t_room_list *room;

	if (!(rlink = (t_room_links*)malloc(sizeof(t_room_links) * 1)) ||
			!(room = get_room(room_name, infos)))
		return (NULL);
	rlink->room = room;
	rlink->next = NULL;
	return (rlink);
}

int					add_room(char *room_name, int roomtype, t_recurse *infos)
{
	t_room_list *rlist_local;

	if (!infos->room_list
			&& !(infos->room_list = new_room(room_name, roomtype)))
		return (0);
	if (!get_room(room_name, infos))
	{
		if (!(rlist_local = new_room(room_name, roomtype)))
			return (0);
		rlist_local->next = infos->room_list;
		infos->room_list = rlist_local;
	}

	return (1);
}

static int			add_lroom(char *room_name,
t_room_links *new_link, t_recurse *infos)
{
	t_room_list *room;

	if (!(room = get_room(room_name, infos)))
		return (0);
	new_link->next = room->l_rooms;
	room->l_rooms = new_link;
	room->number_of_links++;
	return (1);
}
//TODO check if free frees 2dim arrays
int					add_link(char *line, t_recurse *infos)
{
	char			**rooms;
	char			*room1;
	char			*room2;

	if (!(ft_count_words(line, '-') == 2))
		return (0);
	rooms = ft_strsplit(line, '-');
	room1 = rooms[0];
	room2 = rooms[1];
	if (get_room(room1, infos) && get_room(room2, infos)
	&& add_lroom(room1, new_room_link(room2, infos), infos)
	&& add_lroom(room2, new_room_link(room1, infos), infos))
	{
		free(rooms[0]);
		free(rooms[1]);
		free(rooms);
		return (1);
	}
	free(rooms[0]);
	free(rooms[1]);
	free(rooms);
	return (0);
}
