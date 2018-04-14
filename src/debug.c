/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 16:51:52 by mfonteni          #+#    #+#             */
/*   Updated: 2018/04/14 19:32:02 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int print_lem_struct(t_lem_list *list)
{
	t_lem_list *lem_list = list;
	if (!list)
	{
		ERROR("lem_list not init");
		return (0);
	}
	while (lem_list)
	{
		ft_printf("{BLUE}L-%d{EOC}\n", lem_list->lem);
		ft_printf ("{BLUE}Room:%s{EOC}\n\n", lem_list->room);
		lem_list = lem_list->next;
	}
	return (1);
}

void	print_struct(t_recurse *recurse)
{
	t_room_list *rlist;
	t_lem_list *lem_list;
	t_room_list	*next_room;
	t_room_links *linked_rooms;

	if (!(rlist = recurse->room_list)
		|| !(lem_list = recurse->lem_list)
		|| !(next_room = recurse->next_room))
	{
		ERROR("Cannot access one of the list elements");
		return ;
	}
	while (rlist)
	{
		linked_rooms = rlist->l_rooms;
		ft_printf("{BLUE}Room:%s{EOC}\n", rlist->name);

		if (rlist->type == START)
			INFO("START");
		else if (rlist->type == END)
			INFO("END");
		else if (rlist->type == CLASSICROOM)
			INFO("CLASSICROOM");

		ft_printf("{BLUE}Number of links:%d{EOC}\n", rlist->number_of_links);
		INFO("Linked to :");
		while (linked_rooms)
		{
			ft_printf("-{BLUE}%s{EOC}\n", linked_rooms->room->name);
			linked_rooms = linked_rooms->next;
		}
		rlist = rlist->next;
		ft_putchar('\n');
	}
	print_lem_struct(lem_list);

//	if (next_room)
//		printf("Le resultat de la recherche de room est %s\n", next_room->name);
}
