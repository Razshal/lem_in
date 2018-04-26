/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 17:39:17 by mfonteni          #+#    #+#             */
/*   Updated: 2018/04/26 14:51:03 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

t_room_list		*get_room(char *room_name, t_recurse *infos)
{
	t_room_list *current;

	current = infos->room_list;
	while (room_name && infos->room_list && current && current->name)
	{
		if (!ft_strcmp(current->name, room_name))
			return (current);
		current = current->next;
	}
	return (NULL);
}

t_room_links	*get_lroom_pos(t_room_list *room, int link_num)
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

char			*get_start_name(t_room_list *room)
{
	t_room_list *temp;

	temp = room;
	while (temp)
	{
		if (temp->type == START)
			return (temp->name);
		temp = temp->next;
	}
	return (NULL);
}

t_room_list		*get_last_item(t_room_list *rlist)
{
	t_room_list *local_rlist;

	local_rlist = rlist;
	while (local_rlist->next)
		local_rlist = local_rlist->next;
	return (local_rlist);
}

t_room_links	*get_last_item_link(t_room_links *rlink)
{
	t_room_links *local_rlink;

	local_rlink = rlink;
	while (local_rlink->next)
		local_rlink = local_rlink->next;
	return (local_rlink);
}
