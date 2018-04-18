/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_lists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 14:57:38 by mfonteni          #+#    #+#             */
/*   Updated: 2018/04/14 17:23:01 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static t_lem_list	*new_lem(int lem_num, char *room_name)
{
	t_lem_list *llist;

	if (!(llist = (t_lem_list*)malloc(sizeof(t_lem_list) * 1)))
		return (NULL);
	llist->lem = lem_num;
	llist->room = room_name;
	llist->arrived = 0;
	llist->path = NULL;
	llist->next = NULL;
	return (llist);
}

t_lem_list			*get_lem(int lem_num, t_recurse *infos)
{
	t_lem_list *lem;

	lem = infos->lem_list;
	while (lem)
	{
		if (lem && lem->lem == lem_num)
			return (lem);
		lem = lem->next;
	}
	return (NULL);
}

int					add_lem(int lem_num, char *room_name, t_recurse *infos)
{
	t_lem_list *llist_local;

	if (!infos->lem_list && !(infos->lem_list = new_lem(lem_num, room_name)))
		return (0);
	if (!get_lem(lem_num, infos))
	{
		if (!(llist_local = new_lem(lem_num, room_name)))
			return (0);
		llist_local->next = infos->lem_list;
		infos->lem_list = llist_local;
	}
	return (1);
}
