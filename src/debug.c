/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 16:51:52 by mfonteni          #+#    #+#             */
/*   Updated: 2018/04/06 17:02:19 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void	print_struct(t_recurse *recurse)
{
	t_room_list *rlist;
	t_lem_list *lem_list;
	t_room_list	*next_room;

	rlist = recurse->room_list;
	lem_list = recurse->lem_list;
	next_room = recurse->next_room;

	while (rlist)
	{
		printf("%s\n", rlist->name);
		if (rlist->type == START)
			printf("START\n");
		else if (rlist->type == END)
			printf("END\n");
		else if (rlist->type == CLASSICROOM)
			printf("CLASSICROOM\n");
		rlist = rlist->next;
	}
	while (lem_list)
	{
		printf("L-%d\n", lem_list->lem);
		printf ("%s\n", lem_list->room);
	}
	printf("Le resultat de la recherche de room est %s\n", next_room->name);
}
