/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:40:36 by mfonteni          #+#    #+#             */
/*   Updated: 2018/04/26 12:36:46 by mfonteni         ###   ########.fr       */
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
//TODO: check if second return 0 condition realy frees
static int	split_and_add_room(char *line, int type, t_recurse *infos)
{
	char	**room;
	char	*room_name;
	t_coord coords;

	if (ft_count_words(line, ' ') != 3)
		return (0);
	room = ft_strsplit(line, ' ');
	room_name = room[0];
	if (!ft_str_isdigit(room[1]) || !ft_str_isdigit(room[2]))
	{
		delete_array(room);
		return (0);
	}
	coords.x = ft_atoi(room[1]);
	coords.y = ft_atoi(room[2]);
	free(room[1]);
	free(room[2]);
	free(room);
	return (add_room(room_name, type, coords, infos));
}

static int	parse_line(t_recurse *infos)
{
	if (!infos->line || !infos->line[0]
	|| ft_strlen(infos->line) < 2 || infos->line[0] == 'L')
		return (0);
	else if (infos->line[0] == '#' && infos->line[1] != '#')
		return (1);
	else if (ft_strchr(infos->line, '-'))
		return(add_link(infos->line, infos));
	else if (infos->line[0] == '#' && infos->line[1] == '#')
	{
		if (!ft_strcmp(infos->line, "##end")
		&& noleaks_get_next_line(0, &infos->line))
			return (split_and_add_room(infos->line, END, infos));
		else if (!ft_strcmp(infos->line, "##start")
		&& noleaks_get_next_line(0, &infos->line))
			return (split_and_add_room(infos->line, START, infos));
		return (0);
	}
	return (split_and_add_room(infos->line, CLASSICROOM, infos));
}

int			lists_init(t_recurse **infos)
{
	(*infos)->lem_list = NULL;
	(*infos)->room_list = NULL;
	(*infos)->line = NULL;

	if (get_next_line(0, &(*infos)->line) < 1)
		return (0);
	if (!(*infos)->line || !lem_init(ft_atoi((*infos)->line), *infos))
		return (0);
	while (noleaks_get_next_line(0, &(*infos)->line) > 0)
	{
		if (!parse_line(*infos))
		{
			ft_memdel((void**)&(*infos)->line);
			return (0);
		}
	}
	ft_memdel((void**)&(*infos)->line);
	if (!(*infos)->lem_list || !(*infos)->room_list)
		return (0);
	return (1);
}
