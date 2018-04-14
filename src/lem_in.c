/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:37:42 by mfonteni          #+#    #+#             */
/*   Updated: 2018/04/14 17:38:38 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static int	all_lems_in_end(t_recurse *infos)
{
	t_lem_list	*local_lem;

	local_lem = infos->lem_list;
	while (local_lem)
	{
		if (!is_end_room(local_lem->room, infos->room_list))
			return (0);
		local_lem = local_lem->next;
	}
	return (1);
}

static int	moove_lems(t_recurse *infos)
{
	t_lem_list	*local_lem;
//	int			destination;

	local_lem = infos->lem_list;
	while (!all_lems_in_end(infos))
	{
		if (get_lem(1, infos))
			ft_printf("test");
	}
	return (1);
}

int main(void)
{
	t_recurse *infos;

	if (!(infos = (t_recurse*)malloc(sizeof(t_recurse) * 1)))
		return (0);
	if (!lists_init(&infos))
	{
		print_lem_struct(infos->lem_list);
		ft_putstr("ERROR");
		return (0);
	}
	if (!moove_lems(infos))
		BUGERROR;
	print_struct(infos);
}
