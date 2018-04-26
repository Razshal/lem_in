/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_lem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:12:18 by abouvero          #+#    #+#             */
/*   Updated: 2018/04/26 18:56:14 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void 	recfr_path(t_path *path)
{
	if (!path)
		return ;
	if (path->next)
		recfr_path(path->next);
	ft_memdel((void**)&path);
}

// void 	free_paths(t_lem_list *lem)
// {
// 	while (lem)
// 	{
// 		recfr_path(lem->beg_path);
// 		lem = lem->next;
// 	}
// }

void		free_paths(t_attr_paths *tab, int len)
{
	int		i;

	i = -1;
	while (++i < len)
		ft_memdel((void**)&tab[i].path);
}

int 	all_arrived(t_lem_list *lem)
{
	while (lem)
	{
		if (!lem->arrived)
			return (0);
		lem = lem->next;
	}
	return (1);
}

void	print_path(t_path *path)
{
	while (path)
	{
		ft_printf("%s", path->room->name);
		path->next ? ft_printf(" -> ") : ft_printf("\n");
		path = path->next;
	}
}

void	get_diff_path(t_lem_list *lem, t_room_list *rl)
{
	while (lem)
	{
		lem->path = get_path(rl);
		lem->beg_path = lem->path;
		print_path(lem->path);
		lem = lem->next;
	}
}

int		get_path_nbr(t_lem_list *lem)
{
	int 	i;

	i = 0;
	while (lem)
	{
		if (!lem->path)
			return (i);
		lem = lem->next;
		i++;
	}
	return (i);
}

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
			lem->beg_path = tab[i].path;
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

	get_diff_path(lem, rl);
	lem_nbr = ft_list_size_lem(lem);
	path_nbr = get_path_nbr(lem);
	ft_printf("nbr chemin : %d | nbr lem : %d | taille : %d\n", path_nbr, lem_nbr, lem->path->length);
	if (!(tab = calc_lems_by_path(lem, lem_nbr, path_nbr)))
		return (NULL);
	assign_lem(lem, tab);
	//ft_memdel((void**)&tab);
	*len = path_nbr;
	return (tab);
}

void	moove_lems(t_lem_list *lem, t_room_list *rl)
{
	t_lem_list		*beg;
	t_attr_paths	*tab;
	int				len;

	beg = lem;
	if (!(tab = attr_lems(lem, rl, &len)))
		return ;
	// while (lem)
	// {
	// 	ft_printf("%d : ", lem->lem);
	// 	if (lem->path)
	// 		print_path(lem->path);
	// 	else
	// 		ft_printf("(null)");
	// 	ft_printf("\n");
	// 	lem = lem->next;
	// }
	while (!all_arrived(beg))
	{
		lem = beg;
		while (lem)
		{
			if (!lem->path->next)
				lem->arrived = 1;
			else if (!lem->arrived && !lem->path->next->room->occupied)
			{
				ft_printf("L%d-%s ", lem->lem, lem->path->next->room->name);
				lem->path->room->occupied = 0;
				lem->path = lem->path->next;
				lem->path->room->occupied = lem->path->next ? 1 : 0;
			}
			lem = lem->next;
		}
		ft_printf("\n");
	}
	free_paths(tab, len);
	ft_memdel((void**)&tab);
	//free_paths(beg);
}