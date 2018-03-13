/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:37:42 by mfonteni          #+#    #+#             */
/*   Updated: 2018/03/13 18:26:15 by mfonteni         ###   ########.fr       */
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

	line = NULL;
	if (!(infos = (t_recurse*)malloc(sizeof(t_recurse) * 1))
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
	return (1);
}

int main(void)
{
	t_recurse *infos;

	if (!lists_init(infos))
		ft_printf("{RED}Bad datas, please check your file{EOC}\n");
}
