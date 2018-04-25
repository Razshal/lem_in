/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:24:02 by abouvero          #+#    #+#             */
/*   Updated: 2018/04/16 12:25:01 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void 	recfr_path(t_path *path)
{
	if (!path)
		return ;
	if (path->next)
		recfr_path(path->next);
	ft_memdel((void**)&path);
}

void 	free_paths(t_lem_list *lem)
{
	while (lem)
	{
		recfr_path(lem->beg_path);
		lem = lem->next;
	}
}

int 	all_arrived(t_lem_list *lem)
{
	while (lem)
	{
		if (!lem->arrived)
			return (0);
		lem = lem->next;
	}
	return (1);
}

void	print_path(t_path *path)
{
	while (path)
	{
		ft_printf("%s", path->room->name);
		path->next ? ft_printf(" -> ") : ft_printf("\n");
		path = path->next;
	}
}

void	attr_lems(t_lem_list *lem, t_room_list *rl)
{
	while (lem)
	{
		lem->path = get_path(rl);
		lem->beg_path = lem->path;
		lem = lem->next;
	}
}

void	moove_lems(t_lem_list *lem, t_room_list *rl)
{
	t_lem_list *beg;

	beg = lem;
	attr_lems(lem, rl);
	while (lem)
	{
		ft_printf("%d : ", lem->lem);
		if (lem->path)
			print_path(lem->path);
		else
			ft_printf("(null)");
		ft_printf("\n");
		lem = lem->next;
	}
	// SUCCESSM("Solution :");
	// while (!all_arrived(beg))
	// {
	// 	lem = beg;
	// 	while (lem)
	// 	{
	// 		if (!lem->path->next)
	// 			lem->arrived = 1;
	// 		else if (!lem->arrived && !lem->path->next->room->occupied)
	// 		{
	// 			ft_printf("L%d-%s ", lem->lem, lem->path->next->room->name);
	// 			lem->path->room->occupied = 0;
	// 			lem->path = lem->path->next;
	// 			lem->path->room->occupied = lem->path->next ? 1 : 0;
	// 		}
	// 		lem = lem->next;
	// 	}
	// 	ft_printf("\n");
	// }
	// free_paths(beg);
}