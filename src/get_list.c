/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searching.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 12:48:17 by mfonteni          #+#    #+#             */
/*   Updated: 2018/03/12 19:23:25 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

t_room_list *get_room(int room, t_room_list *rlist)
{
	t_room_list *current;

	current = rlist;
	while (current)
	{
		if (current->room_number == room)
			return (current);
	}
	return (NULL);
}

t_room_links *get_room_link_pos(int room_num, int link_num, t_room_list *rlist)
{
	t_room_links	*link;
	int				count;

	count = -1;
	link = get_room(room_num, rlist)->linked_rooms;
	while (link && ++count < link_num)
		link = link->next;
	if (count == link_num)
		return (link);
	return (NULL);
}

t_room_links *get_room_link_num(int room_num, int rlink_num, t_room_list *rlist)
{
	t_room_links	*link;

	link = get_room(room_num, rlist)->linked_rooms;
	while (link)
	{
		if (link->room->room_number == rlink_num)
			return (link);
		link = link->next;
	}
	return (NULL);
}

t_room_list *get_last_item(t_room_list *rlist)
{
	t_room_list *local_rlist;

	local_rlist = rlist;
	while (local_rlist->next)
		local_rlist = local_rlist->next;
	return (local_rlist);
}

t_room_links *get_last_item_link(t_room_links *rlink)
{
	t_room_links *local_rlink;

	local_rlink = rlink;
	while (local_rlink->next)
		local_rlink = local_rlink->next;
	return (local_rlink);
}
