/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 17:39:17 by mfonteni          #+#    #+#             */
/*   Updated: 2018/05/02 16:53:02 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

t_room_list	*get_room(char *room_name, t_recurse *infos)
{
	t_room_list *current;

	current = infos->room_list;
	while (room_name && infos->room_list && current && current->name)
	{
		if (!ft_strcmp(current->name, room_name))
			return (current);
		current = current->next;
	}
	return (NULL);
}

t_room_list	*get_start(t_room_list *rl)
{
	while (rl)
	{
		if (rl->type == START)
			return (rl);
		rl = rl->next;
	}
	return (NULL);
}
