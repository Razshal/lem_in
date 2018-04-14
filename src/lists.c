/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 13:13:51 by mfonteni          #+#    #+#             */
/*   Updated: 2018/04/14 18:38:20 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

t_room_list		*new_room(char *room_name, int room_type)
{
	t_room_list *rlist;

	if (!(rlist = (t_room_list*)malloc(sizeof(t_room_list) * 1)))
		return (NULL);
	rlist->name = room_name;
	rlist->type = room_type;
	rlist->l_rooms = NULL;
	rlist->next = NULL;
	return (rlist);
}

t_room_links	*new_room_link(t_room_list *room)
{
	t_room_links *rlink;

	if (!(rlink = (t_room_links*)malloc(sizeof(t_room_links) * 1)))
		return (NULL);
	rlink->room = room;
	rlink->next = NULL;
	return (rlink);
}

int				add_room(char *room_name, int roomtype, t_recurse *infos)
{
	t_room_list *rlist_local;

	if (!infos->room_list
			&& !(infos->room_list = new_room(room_name, roomtype)))
		return (0);
	if (!get_room(room_name, infos->room_list))
	{
		rlist_local = new_room(room_name, roomtype);
		rlist_local->next = infos->room_list;
		infos->room_list = rlist_local;
	}
	return (1);
}

static int		add_lroom(t_room_links *new, t_room_links **old)
{
	if (!new)
		return (0);
	new->next = *old;
	*old = new;
	return (1);
}
//TODO check if free frees 2dim arrays
int				add_link(char *line, t_room_list *rlist)
{
	char			**rooms;
	char			*room1;
	char			*room2;
	t_room_links	*links;
	t_room_links	*links2;

	if (!(ft_count_words(line, '-') == 2))
		return (0);
	rooms = ft_strsplit(line, '-');
	room1 = rooms[0];
	room2 = rooms[1];
	if (!get_room(room1, rlist))
		ERROR("NO ROOM 1");
	if (!get_room(room2, rlist))
		ERROR("NO ROOM 2");
	if (get_room(room1, rlist) && get_room(room2, rlist))
	{
		links = get_room(room1, rlist)->l_rooms;
		links2 = get_room(room2, rlist)->l_rooms;
		if (add_lroom(new_room_link(get_room(room2, rlist)), &links)
				&& add_lroom(new_room_link(get_room(room1, rlist)), &links2))
		{
			free(rooms);
			return (1);
		}
	}
	free(rooms);
	return (0);
}
