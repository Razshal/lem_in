/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searching.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 12:48:17 by mfonteni          #+#    #+#             */
/*   Updated: 2018/03/12 14:52:26 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

t_room_list *get_room(int room, t_room_list *rlist)
{
	t_room_list *current;

	current = rlist;
	while (current)
	{
		if (current->room_number == room)
			return (current);
	}
	return (NULL);
}
