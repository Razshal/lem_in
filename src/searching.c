/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searching.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 12:48:17 by mfonteni          #+#    #+#             */
/*   Updated: 2018/03/14 13:35:19 by mfonteni         ###   ########.fr       */
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
		if (current->room_num == room && current->room_type == END)
			return (1);
	}
	return (0);
}

int			searching(int start_room, int link, int moove_c, t_recurse *infos)
{
	int test;
	int res;
	t_room_list *best_path;
	t_room_list *lroom;

	res = INTMAX;
	if (is_end_room(start_room, infos->room_list))
		return (SUCCESS);
	if (!get_lroom_pos(start_room, 1, infos->room_list))
		return (FAILURE);
	while ((lroom = get_lroom_pos(start_room, link, infos->room_list)->room))
	{
		if ((test = searching(lroom->room_num, link, moove_c + 1, infos)) < res)
		{
			res = test;
			best_path =
				get_lroom_pos(start_room, link, infos->room_list)->room;
		}
		link++;
	}
	infos->next_room = best_path;
	return (moove_c);
}
