/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 16:51:52 by mfonteni          #+#    #+#             */
/*   Updated: 2018/04/06 18:37:53 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"
#define FLUSH fflush(stdout)

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
		{
			printf("START\n"); FLUSH;
		}
		else if (rlist->type == END)
		{
			printf("END\n"); FLUSH;
		}
		else if (rlist->type == CLASSICROOM)
		{
			printf("CLASSICROOM\n"); FLUSH;
		}
		rlist = rlist->next;
	}
	while (lem_list)
	{
		printf("L-%d\n", lem_list->lem); FLUSH;
		printf ("%s\n", lem_list->room); FLUSH;
	}
//	if (next_room)
//		printf("Le resultat de la recherche de room est %s\n", next_room->name);
}
