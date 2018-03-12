/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:37:42 by mfonteni          #+#    #+#             */
/*   Updated: 2018/03/12 13:21:06 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"


static int lists_init(t_recurse *infos)
{
	char *str;

	if (!(infos = (t_recurse*)malloc(sizeof(t_recurse) * 1)))
		return (0);
	while (get_next_line(0, &str))
	{

	}

	return (1);
}


int main(void)
{
	t_recurse *infos;

	lists_init(infos);
	
}
