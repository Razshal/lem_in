/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:09:25 by mfonteni          #+#    #+#             */
/*   Updated: 2018/04/15 19:30:38 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void	delete_array(char **array)
{
	int count;

	count = 0;
	if (array)
		while (array[count])
			free(array[count++]);
	free(array);
}

static void	delete_lem_list(t_recurse *infos)
{
	t_lem_list *next;

	if (!infos->lem_list)
		return;
	next = infos->lem_list;
	free(infos->lem_list);
	infos->lem_list = next;
	delete_lem_list(infos);
}

static void	delete_linked_rooms_list(t_room_links **links)
{
	t_room_links *next;

	if (!*links)
		return;
	next = (*links)->next;
	free(*links);
	*links = next;
	delete_linked_rooms_list(links);
}

static void	delete_room_list(t_recurse *infos)
{
	t_room_list		*next;
	t_room_links	*next_link;

	if (!infos->room_list)
		return;
	next = infos->room_list;
	delete_linked_rooms_list(&infos->room_list->l_rooms);
	free(infos->room_list);
	infos->room_list = next;
	delete_room_list(infos);
}

void	delete_struct(t_recurse *infos)
{
	t_lem_list *llist;
	t_lem_list *llist_next;

	llist = infos->lem_list->next;
	while (infos->lem_list)
	{
		free(infos->lem_list);
		infos->lem_list = llist;
		llist = infos->lem_list->next;
	}
	if (infos->next_room)
		free(infos->next_room);
}