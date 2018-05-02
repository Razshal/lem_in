/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:13:11 by abouvero          #+#    #+#             */
/*   Updated: 2018/05/02 17:24:32 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static int		init_weight(t_room_list *rl)
{
	t_room_list *beg;

	beg = rl;
	restart_weight(rl);
	while (rl)
	{
		if (rl->weight == -1 && initialized(rl->l_rooms) && rl->type != START)
		{
			if ((rl->weight = get_min(rl->l_rooms)) == -1)
				return (1);
			rl = beg;
		}
		rl = rl->next;
	}
	return (0);
}

static t_path	*add_path(t_path *path, t_room_list *room)
{
	t_path *new;
	t_path *beg;

	room->traffic = room->type == END ? 0 : 1;
	if (!(new = (t_path*)malloc(sizeof(t_path))))
		return (NULL);
	new->next = NULL;
	new->room = room;
	new->length = 0;
	beg = path;
	if (!path)
		return (new);
	while (path->next)
		path = path->next;
	path->next = new;
	return (beg);
}

static t_path	*solve_path(t_room_list *rl)
{
	t_room_links	*links;
	t_room_list		*room;
	t_path			*path;

	path = NULL;
	path = add_path(path, rl);
	while (last(path)->room->type != END)
	{
		links = last(path)->room->l_rooms;
		if ((room = get_min_addr(links)))
			path = add_path(path, room);
		else
		{
			recfr_path(path);
			return (NULL);
		}
	}
	return (path);
}

static int		ft_list_size_path(t_path *path)
{
	return (!path ? 0 : 1 + ft_list_size_path(path->next));
}

t_path			*get_path(t_room_list *rl)
{
	t_path *path;

	if (init_weight(rl))
		return (NULL);
	if (!(path = solve_path(get_start(rl))))
		return (NULL);
	path->length = ft_list_size_path(path);
	return (path);
}
