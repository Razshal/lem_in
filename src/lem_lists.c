/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_lists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 14:57:38 by mfonteni          #+#    #+#             */
/*   Updated: 2018/04/14 12:31:55 by mfonteni         ###   ########.fr       */
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
	llist->next = NULL;
	return (llist);
}

t_lem_list	*get_lem(int lem_num, t_lem_list *llist)
{
	t_lem_list *lem;

	lem = llist;
	while (lem && lem->lem != lem_num)
	{
		if (lem->lem == lem_num)
			return (lem);
		lem = lem->next;
	}
	return (NULL);
}

int			add_lem(int lem_num, char *room_name, t_lem_list **llist)
{
	t_lem_list *llist_local;

	if (!*llist && !(*llist = new_lem(lem_num, room_name)))
		return (0);
	if (!get_lem(lem_num, *llist))
	{
		if (!(llist_local = new_lem(lem_num, room_name)))
			return (0);
		llist_local->next = *llist;
		*llist = llist_local;
	}
	return (1);
}
