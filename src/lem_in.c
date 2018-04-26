/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:37:42 by mfonteni          #+#    #+#             */
/*   Updated: 2018/04/26 13:47:35 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int main(void)
{
	t_recurse	*infos;
	t_map		*map;

	if (!(infos = (t_recurse*)malloc(sizeof(t_recurse) * 1))
		|| !(map = (t_map*)malloc(sizeof(t_map) * 1)))
		return (0);
	map->str = NULL;
	map->next = NULL;
	if (!lists_init(&infos, &map))
	{
		ft_putstr("ERROR");
		return (0);
	}
	display_map(map);
	print_struct(infos);
	//solver(infos->room_list);
	moove_lems(infos->lem_list, infos->room_list);
	//delete_struct(infos);
}