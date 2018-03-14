/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:37:42 by mfonteni          #+#    #+#             */
/*   Updated: 2018/03/14 13:12:16 by mfonteni         ###   ########.fr       */
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

static int lists_init(t_recurse *infos)
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
		if (ft_strchr(line, '-') && !add_link(line, infos->room_list))
				return (0);
		else if (ft_strstr(line, "##end")
				&& (!noleaks_get_next_line(0, &line)
				|| !add_room(ft_atoi(line), END, infos->room_list)))
			return (0);
		else if ((ft_strstr(line, "##start")
					&& (!noleaks_get_next_line(0, &line)
					|| !add_room(ft_atoi(line), START, infos->room_list))))
			return (0);
		else if (!add_room(ft_atoi(line), CLASSICROOM, infos->room_list))
			return (0);
	}
	ft_memdel((void**)&line);
	return (1);
}

static int	are_all_lems_in_end(t_recurse *infos)
{
	int			are_they;
	t_lem_list	*local_lem;

	are_they = 1;
	local_lem = infos->lem_list;
	while (local_lem)
	{
		if (!is_end_room(local_lem->room, infos->room_list))
			are_they = 0;
		local_lem = local_lem->next;
	}
	return (are_they);
}

static int	moove_lems(t_recurse *infos)
{
	t_lem_list	*local_lem;
	int			destination;

	local_lem = infos->lem_list;
	while (!are_all_lems_in_end(infos))
	{
		if (get_lem(1, local_lem))

	}
}

int main(void)
{
	t_recurse *infos;

	if (!lists_init(infos))
		ft_printf("{RED}Bad datas, please check your file{EOC}\n");
}
