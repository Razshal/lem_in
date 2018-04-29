/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:37:42 by mfonteni          #+#    #+#             */
/*   Updated: 2018/04/29 15:26:26 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int	main(void)
{
	t_recurse	*infos;
	t_map		*map;

	if (!(infos = (t_recurse*)malloc(sizeof(t_recurse) * 1))
		|| !(map = (t_map*)malloc(sizeof(t_map) * 1)))
		return (0);
	map->str = NULL;
	map->next = NULL;
	infos->lem_list = NULL;
	infos->room_list = NULL;
	infos->line = NULL;
	if (!lists_init(&infos, &map)
	|| !moove_lems(infos->lem_list, infos->room_list, map))
	{
		ft_putstr("ERROR\n");
		delete_struct(infos);
		free_map(&map);
		return (0);
	}
	//print_struct(infos);
	//solver(infos->room_list);
	delete_struct(infos);
	free_map(&map);
}
