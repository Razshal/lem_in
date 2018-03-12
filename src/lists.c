/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 13:13:51 by mfonteni          #+#    #+#             */
/*   Updated: 2018/03/12 16:51:29 by mfonteni         ###   ########.fr       */
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
	return (rlist);
}

int	alloc_and_add_room(int room_number, int roomtype, t_room_list *rlist)
{
	t_room_list *rlist_local;

	if (!rlist && !(rlist = new_room(room_number, roomtype)))
		return (0);
	rlist_local = rlist;
	if (!get_room(room_number, rlist))
		get_last_link(rlist)->next = new_room(room_number, roomtype);

}
