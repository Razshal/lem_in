/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:15:20 by mfonteni          #+#    #+#             */
/*   Updated: 2018/04/27 14:58:49 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		append_line(char *str, t_map **map)
{
	t_map *new_line;

	if (!str || !map || !(new_line = (t_map*)malloc(sizeof(t_map) * 1)))
		return (0);
	new_line->str = str;
	new_line->next = *map;
	*map = new_line;
	return (1);
}

int		display_map(t_map *map)
{
	t_map *local;

	local = map;
	if (!map)
		return (0);
	if (map->next)
		display_map(map->next);
	ft_putendl(map->str);
	return (1);
}

void	free_map(t_map **map)
{
	if ((*map)->next)
		free_map(&(*map)->next);
	free((*map)->str);
	free(*map);
}
