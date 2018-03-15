/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:40:36 by mfonteni          #+#    #+#             */
/*   Updated: 2018/03/15 16:05:10 by mfonteni         ###   ########.fr       */
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
				lem_nu--, get_start_num(infos->room_list), infos->lem_list))
			return (0);
	}
	return (1);
}

static int	is_valid_room(char *line)
{
	int count;
	int wordcount;
}

static int	check_and_add_the_right_data(char *line, t_recurse *infos)
{
	if (ft_strchr(line, '-') && !add_link(line, infos->room_list))
		return (0);
	else if (ft_strstr(line, "##end") && !ft_strstr(line, "##end")[5]
			&& (!noleaks_get_next_line(0, &line)
			|| !add_room(ft_atoi(line), END, infos->room_list)))
		return (0);
	else if (ft_strstr(line, "##start") && !(ft_strstr(line, "##start")[7]
				&& (!noleaks_get_next_line(0, &line)
				|| !add_room(ft_atoi(line), START, infos->room_list))))
		return (0);
	else if (!add_room(ft_atoi(line), CLASSICROOM, infos->room_list))
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
/*
static int	parser(t_recurse *infos)
{

}*/
