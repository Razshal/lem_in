/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 13:13:51 by mfonteni          #+#    #+#             */
/*   Updated: 2018/03/12 19:24:46 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

t_room_list *new_room(int room_number, int room_type)
{
	t_room_list *rlist;

	if (!(rlist = (t_room_list*)malloc(sizeof(t_room_list) * 1)))
		return (NULL);
	rlist->room_number = room_number;
	rlist->room_type = room_type;
	rlist->linked_rooms = NULL;
	rlist->next = NULL;
	return (rlist);
}

t_room_links *new_room_link(t_room_list *room, int room_type)
{
	t_room_links *rlink;

	if (!(rlink = (t_room_links*)malloc(sizeof(t_room_links) * 1)))
		return (NULL);
	rlink->room = room;
	rlink->next = NULL;
	return (rlink);
}

int	alloc_and_add_room(int room_number, int roomtype, t_room_list *rlist)
{
	t_room_list *rlist_local;

	if (!rlist && !(rlist = new_room(room_number, roomtype)))
		return (0);
	rlist_local = rlist;
	if (!get_room(room_number, rlist))
		get_last_item(rlist)->next = new_room(room_number, roomtype);
	if (get_room(room_number, rlist)->room_type != roomtype)
		get_room(room_number, rlist)->room_type = roomtype;
	return (1);
}

int add_link(char *line, t_room_list *rlist)
{
	int				room1;
	int				room2;
	t_room_links	*links;

	room1 = ft_atoi(line);
	room2 = ft_atoi(&line[2]);
	if (!get_room(room1, rlist))
		alloc_and_add_room(room1, CLASSICROOM, rlist);
	links = get_room(room1, rlist)->linked_rooms;
	if (links && !get_room_link_num(room1

}
