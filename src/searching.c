/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searching.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 12:48:17 by mfonteni          #+#    #+#             */
/*   Updated: 2018/03/11 17:30:13 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static int is_end_room(int room, t_room_list *list)
{
	t_room_list *current;

	current = list;
	while (current)
	{
		if (current->room == room && current->roomtype == END)
			return (1);
	}
	return (0);
}

static t_room_list *get_room(int room, t_room_list *rlist)
{
	t_room_list *current;

	current = rlist;
	while (current)
	{
		if (current->room == room)
			return (current);
	}
	return (NULL);
}

static int get_linkedroom(int desired_room, int desired_link, t_recurse *infos)
{
	t_room_list *room;

	return (get_room(desired_room, infos->room_list)->links[desired_link]);
}

int searching(int actual_room, int link, int moove_count, t_recurse *infos)
{
	int test;
	int res;
	int room;

	res = INTMAX;
	if (is_end_room(actual_room, infos->room_list))
		return (SUCCESS);
	while ((room = get_linkedroom(actual_room, link, infos)) != ENDOFTAB)
	{
		if ((test = searching(get_linkedroom(actual_room, link, infos),
				link, moove_count + 1, infos)) < res)
		{
			res = test;
			room = get_linkedroom(actual_room, link, infos);
		}
		link++;
	}
	return (moove_count);
}
