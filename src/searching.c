/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searching.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 12:48:17 by mfonteni          #+#    #+#             */
/*   Updated: 2018/03/11 14:50:33 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int searching(int actual_room, int link, int moove_count, t_room_list *list)
{
	int testres;
	int res;
	int room;

	res = INTMAX;
	if (is_end_case(actual_room))
		return (SUCCESS);
	while ((room = get_linkedroom(actual_room, link)) != ENDOFTAB)
	{
		if ((testres = searching(get_linkedroom(actual_room, link))) < res)
		{
			res = testres;
			room = get_linkedroom(actual_room, link);
		}
	}
}
