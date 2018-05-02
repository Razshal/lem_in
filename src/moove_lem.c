/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_lem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:12:18 by abouvero          #+#    #+#             */
/*   Updated: 2018/05/02 13:08:25 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		ft_list_size_lem(t_lem_list *lem)
{
	return (!lem ? 0 : 1 + ft_list_size_lem(lem->next));
}

void	assign_lem(t_lem_list *lem, t_attr_paths *tab)
{
	int		i;

	i = 0;
	while (lem)
	{
		if (!tab[i].lem_nbr)
			i++;
		if (tab[i].lem_nbr > 0)
		{
			lem->path = tab[i].path;
			tab[i].lem_nbr -= 1;
		}
		lem = lem->next;
	}
}

t_attr_paths		*attr_lems(t_lem_list *lem, t_room_list *rl, int *len)
{
	int				lem_nbr;
	int				path_nbr;
	t_attr_paths	*tab;

	if (!get_diff_path(lem, rl))
		return (NULL);
	lem_nbr = ft_list_size_lem(lem);
	path_nbr = get_path_nbr(lem);
	if (!(tab = calc_lems_by_path(lem, lem_nbr, path_nbr)))
		return (NULL);
	assign_lem(lem, tab);
	*len = path_nbr;
	return (tab);
}

int		moove_lems(t_lem_list *lem, t_room_list *rl, t_map *map)
{
	t_lem_list		*beg;
	t_attr_paths	*tab;
	int				len;

	beg = lem;
	if (!(tab = attr_lems(lem, rl, &len)))
		return (0);
	display_map(map);
	ft_putchar('\n');
	while (!all_arrived(beg))
	{
		lem = beg;
		while (lem)
		{
			lem->arrived = !lem->path->next;
			if (!lem->arrived && !lem->path->next->room->occupied)
			{
				ft_printf("L%d-%s", lem->lem, lem->path->next->room->name);
				lem->path->room->occupied = 0;
				lem->path = lem->path->next;
				lem->path->room->occupied = lem->path->next ? 1 : 0;
				lem->arrived = !lem->path->next;
				if (lem->next && !lem->next->arrived && !all_arrived(beg))
					ft_putchar(' ');
			}
			lem = lem->next;
		}
		ft_printf("\n");
	}
	free_paths(tab, len);
	ft_memdel((void**)&tab);
	return (1);
}