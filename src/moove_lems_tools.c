/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_lems_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 13:07:45 by abouvero          #+#    #+#             */
/*   Updated: 2018/05/02 13:37:22 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void		recfr_path(t_path *path)
{
	if (!path)
		return ;
	if ((path)->next)
		recfr_path(path->next);
	path->room->traffic = 0;
	ft_memdel((void**)&path);
}

void		free_paths(t_attr_paths *tab, int len)
{
	int		i;

	i = -1;
	while (++i < len)
		recfr_path(tab[i].path);
}

int			all_arrived(t_lem_list *lem)
{
	while (lem)
	{
		if (!lem->arrived)
			return (0);
		lem = lem->next;
	}
	return (1);
}

int			get_diff_path(t_lem_list *lem, t_room_list *rl)
{
	int		done;

	done = 0;
	while (lem)
	{
		lem->path = get_path(rl);
		if (lem->path)
			done = 1;
		lem = lem->next;
	}
	return (done);
}

int			get_path_nbr(t_lem_list *lem)
{
	int i;

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
