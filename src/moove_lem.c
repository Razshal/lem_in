/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_lem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:12:18 by abouvero          #+#    #+#             */
/*   Updated: 2018/05/02 16:25:25 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int				ft_list_size_lem(t_lem_list *lem)
{
	return (!lem ? 0 : 1 + ft_list_size_lem(lem->next));
}

void			assign_lem(t_lem_list *lem, t_attr_paths *tab, int len)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (lem)
	{
		if (i == len || !tab[i].lem_nbr)
			i = 0;
		if (tab[i].lem_nbr)
		{
			lem->path = tab[i].path;
			tab[i].lem_nbr -= 1;
		}
		i++;
		if (!lem->path)
		{
			while (++j < len)
				if (tab[j].lem_nbr)
				{
					lem->path = tab[j].path;
					tab[j].lem_nbr -= 1;
				}
		}
		lem = lem->next;
	}
}

t_attr_paths	*attr_lems(t_lem_list *lem, t_room_list *rl, int *len)
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
	assign_lem(lem, tab, path_nbr);
	*len = path_nbr;
	return (tab);
}

void			print_and_moove(t_lem_list *lem)
{
	int		i;

	i = 0;
	while (lem)
	{
		lem->arrived = lem->path->next ? 0 : 1;
		if (!lem->arrived && !lem->path->next->room->occupied)
		{
			if (i > 0)
				ft_putchar(' ');
			ft_printf("L%d-%s", lem->lem, lem->path->next->room->name);
			lem->path->room->occupied = 0;
			lem->path = lem->path->next;
			lem->path->room->occupied = lem->path->next ? 1 : 0;
			i++;
		}
		lem = lem->next;
	}
}

int				moove_lems(t_lem_list *lem, t_room_list *rl, t_map *map)
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
		print_and_moove(lem);
		if (!all_arrived(beg))
			ft_printf("\n");
	}
	free_paths(tab, len);
	ft_memdel((void**)&tab);
	return (1);
}
