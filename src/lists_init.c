/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:40:36 by mfonteni          #+#    #+#             */
/*   Updated: 2018/03/16 18:09:00 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static int lem_init(int lem_amount, t_recurse *infos)
{
	int lem_nu;

	lem_nu = 1;
	if (lem_amount < 1)
		return (0);
	while (lem_amount > 0)
	{
		if (!add_lem(
				lem_nu--, get_start_name(infos->room_list), infos->lem_list))
			return (0);
	}
	return (1);
}

static int	split_and_add_room(char *line, int type, t_recurse *infos)
{
	char	**rooms;
	int		res;

	rooms = ft_strsplit(line, ' ');
	res = add_room(rooms[0], type, infos->room_list);
	if (!res)
		ft_memdel_array((void***)rooms);
	if (res && rooms[1])
		ft_memdel_array((void***)&rooms[1]);
	return (res);
}
static int	check_and_add_the_right_data(char *line, t_recurse *infos)
{
	if (!line)
		return (0);
	if (ft_strchr(line, '-') && !add_link(line, infos->room_list))
		return (0);
	else if (ft_strstr(line, "##end") && !ft_strstr(line, "##end")[5]
			&& (!noleaks_get_next_line(0, &line)
			|| !split_and_add_room(line, END, infos)))
		return (0);
	else if (ft_strstr(line, "##start") && !(ft_strstr(line, "##start")[7]
			&& (!noleaks_get_next_line(0, &line)
			|| !split_and_add_room(line, START, infos))))
		return (0);
	else if (!split_and_add_room(line, CLASSICROOM, infos))
		return (0);
	return (1);
}

int lists_init(t_recurse *infos)
{
	char *line;

	if ((line = NULL) || !(infos = (t_recurse*)malloc(sizeof(t_recurse) * 1))
			|| !get_next_line(0, &line) || !lem_init(ft_atoi(line), infos))
	{
		ft_memdel((void**)&line);
		return (0);
	}
	while (noleaks_get_next_line(0, &line))
	{
		if (!check_and_add_the_right_data(line, infos))
			return (0);
	}
	ft_memdel((void**)&line);
	return (1);
}
