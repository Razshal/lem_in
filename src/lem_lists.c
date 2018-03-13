/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_lists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 14:57:38 by mfonteni          #+#    #+#             */
/*   Updated: 2018/03/13 15:14:30 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static t_lem_list	*new_lem(int lem_num, int room_num)
{
	t_lem_list *llist;

	if (!(llist = (t_lem_list*)malloc(sizeof(t_lem_list) * 1)))
		return (NULL);
	llist->lem = lem_num;
	llist->room = room_num;
	llist->next = NULL;
	return (llist);
}

t_lem_list	*get_lem(int lem_num, t_lem_list *llist)
{
	t_lem_list *lem;

	lem = llist;
	while (lem && lem->lem != lem_num)
		lem = lem->next;
	return (lem);
}

int			add_lem(int lem_num, int room_num, t_lem_list *llist)
{
	t_lem_list *llist_local;

	if (!llist && !(llist = new_lem(lem_num, room_num)))
		return (0);
	llist_local = llist;
	if (!get_lem(lem_num, llist))
		new_lem(lem_num, room_num)->next = llist;
	return (1);
}
