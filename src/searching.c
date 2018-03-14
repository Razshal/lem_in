/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searching.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 12:48:17 by mfonteni          #+#    #+#             */
/*   Updated: 2018/03/14 16:56:51 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"
//TODO : find a way to take another path if a lem is in the next room

int			is_end_room(int room, t_room_list *list)
{
	t_room_list *current;

	current = list;
	while (current)
	{
		if (current->num == room && current->type == END)
			return (1);
	}
	return (0);
}

int			searching(int start_room, int link, int moove_c, t_recurse *infos)
{
	int res;
	t_room_list *path;
	t_room_list *current_room;

	res = INTMAX;
	current_room = infos->room_list;
	if (current_room->type == END)
		return (SUCCESS);
	if (!get_lroom_pos(current_room, 1))
		return (FAILURE);
	while ((current_room = get_lroom_pos(
				get_room(start_room, infos->room_list), link)->room))
	{
		if ((moove_c = searching(current_room->num, link, moove_c + 1, infos))
				< res && moove_c != FAILURE)
		{
			res = moove_c;
			path = get_lroom_pos(
				get_room(start_room, infos->room_list), link)->room;
		}
		link++;
	}
	infos->next_room = path;
	return (moove_c);
}
