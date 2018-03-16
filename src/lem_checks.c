/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 13:05:18 by mfonteni          #+#    #+#             */
/*   Updated: 2018/03/16 17:22:50 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int	are_lems_in_this_room(char *room_to_check, t_recurse *infos)
{
	t_lem_list	*current_lem;
	int			are_they;

	current_lem = infos->lem_list;
	are_they = 0;
	while (current_lem)
	{
		if (!ft_strcmp(current_lem->room, room_to_check))
			are_they = 1;
		current_lem = current_lem->next;
	}
	return (are_they);
}
