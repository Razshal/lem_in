/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searching.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 12:48:17 by mfonteni          #+#    #+#             */
/*   Updated: 2018/03/20 17:06:23 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

t_room_list *get_room(char *room_name, t_room_list *rlist)
{
	t_room_list *current;

	current = rlist;
	ft_printf("{GREEN}%s\n{EOC}", room_name);
	while (current && room_name && rlist && current->name)
	{
		if (!ft_strcmp(current->name, room_name))
			return (current);
	}
	return (NULL);
}

t_room_links *get_lroom_pos(t_room_list *room, int link_num)
{
	t_room_links	*link;
	int				count;

	count = -1;
	link = room->l_rooms;
	while (link && ++count < link_num)
		link = link->next;
	if (count == link_num)
		return (link);
	return (NULL);
}

t_room_links *get_lroom_name(char *name, int rlink_num, t_room_list *rlist)
{
	t_room_links	*link;
	int				count;

	link = get_room(name, rlist)->l_rooms;
	count = 0;
	while (link)
	{
		if (count == rlink_num)
			return (link);
		link = link->next;
		count++;
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
