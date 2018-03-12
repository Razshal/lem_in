/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searching.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 12:48:17 by mfonteni          #+#    #+#             */
/*   Updated: 2018/03/12 18:31:06 by mfonteni         ###   ########.fr       */
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

t_room_list *get_room_link(int room, t_room_links *rlinks)
{
	t_room_links *current;

	current = rlinks;
	while (current)
	{
		if (current->room_number == room)
			return (current);
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
