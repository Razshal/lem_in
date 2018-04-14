/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:40:36 by mfonteni          #+#    #+#             */
/*   Updated: 2018/04/14 17:05:54 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static int lem_init(int lem_amount, t_recurse *infos)
{
	if (lem_amount < 1)
		return (0);
	while (lem_amount > 0)
	{
		if (!add_lem(lem_amount--, NULL, &(infos->lem_list)))
			return (0);
	}
	return (infos->lem_list != NULL);
}

//TODO check if free frees 2dim arrays
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
	return (add_room(ft_strdup(rooms[0]), type, &(infos->room_list)));
}

static int	parse_line(char *line, t_recurse *infos)
{
//printf("%s\n", line);
	if (!line || line[1] == 'L')
		return (0);
	else if (line[0] == '#' && line[1] != '#')
		return (1);
	else if (ft_strchr(line, '-'))
	{
		if (!add_link(line, infos->room_list))
		{
			ERROR("add link failed");
			return (0);
		}
		else
			return (1);
	}
	else if (line[0] == '#' && line[1] == '#')
	{
		if (ft_strcmp(line, "##end") && noleaks_get_next_line(0, &line)
				&& split_and_add_room(line, END, infos))
			return (1);
		else if (ft_strcmp(line, "##start") && noleaks_get_next_line(0, &line)
				&& split_and_add_room(line, START, infos))
			return (1);
ERROR("bad ## instruction");
		return (0);
	}
	else if (!split_and_add_room(line, CLASSICROOM, infos))
	{
ERROR("failed classic room add");
		return (0);
	}
	return (1);
}

int lists_init(t_recurse *infos)
{
	char *line;

	line = NULL;
	if (!(infos = (t_recurse*)malloc(sizeof(t_recurse) * 1))
			|| !get_next_line(0, &line))
	{
		ft_memdel((void**)&line);
		return (0);
	}
	infos->lem_list = NULL;
	infos->room_list = NULL;
	if (!line || !lem_init(ft_atoi(line), infos))
		return (0);
	print_lem_struct(infos->lem_list);

	while (get_next_line(0, &line))
	{
		if (!parse_line(line, infos))
		{
ERROR("parser rejected line or failed");
			ft_memdel((void**)&line);
			return (0);
		}
	}
	ft_memdel((void**)&line);
	return (1);
}
