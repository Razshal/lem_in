/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 18:36:19 by mfonteni          #+#    #+#             */
/*   Updated: 2018/03/16 18:49:06 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

char		*get_start_name(t_room_list *room)
{
	t_room_list *temp;

	temp = room;
	while (room && temp)
	{
		if (temp->type == START)
			return (temp->name);
		temp = temp->next;
	}
	return (NULL);
}
