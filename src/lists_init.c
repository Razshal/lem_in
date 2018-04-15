/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:40:36 by mfonteni          #+#    #+#             */
/*   Updated: 2018/04/15 13:56:34 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static int	lem_init(int lem_amount, t_recurse *infos)
{
	if (lem_amount < 1)
		return (0);
	while (lem_amount > 0)
	{
		if (!add_lem(lem_amount--, NULL, infos))
			return (0);
	}
	return (infos->lem_list != NULL);
}

static int	split_and_add_room(char *line, int type, t_recurse *infos)
{
	char	**rooms;

	if (ft_count_words(line, ' ') != 3)
		return (0);
	rooms = ft_strsplit(line, ' ');
	if (!ft_str_isdigit(rooms[1]) || !ft_str_isdigit(rooms[2]))
	{
		free(rooms);
		return (0);
	}
	return (add_room(ft_strdup(rooms[0]), type, infos));
}

static int	parse_line(char *line, t_recurse *infos)
{
	if (!line || line[1] == 'L')
		return (0);
	else if (line[0] == '#' && line[1] != '#')
		return (1);
	else if (ft_strchr(line, '-'))
	{
		if (!add_link(line, infos))
			return (0);
	}
	else if (line[0] == '#' && line[1] == '#')
	{
		if (ft_strcmp(line, "##end") && noleaks_get_next_line(0, &line)
				&& split_and_add_room(line, END, infos))
			return (1);
		else if (ft_strcmp(line, "##start") && noleaks_get_next_line(0, &line)
				&& split_and_add_room(line, START, infos))
			return (1);
		return (0);
	}
	else if (!split_and_add_room(line, CLASSICROOM, infos))
		return (0);
	return (1);
}

int			lists_init(t_recurse **infos)
{
	char *line;

	(*infos)->lem_list = NULL;
	(*infos)->room_list = NULL;
	if (!get_next_line(0, &line))
		return (0);
	if (!line || !lem_init(ft_atoi(line), *infos))
		return (0);
	while (get_next_line(0, &line))
	{
		if (!parse_line(line, *infos))
			return (0);
	}
	ft_memdel((void**)&line);
	if (!(*infos)->lem_list || !(*infos)->room_list)
		return (0);
	return (1);
}
