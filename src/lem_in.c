/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:37:42 by mfonteni          #+#    #+#             */
/*   Updated: 2018/03/12 18:04:21 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"


static int lists_init(t_recurse *infos)
{
	char *line;


	if (!(infos = (t_recurse*)malloc(sizeof(t_recurse) * 1)))
		return (0);
	while (get_next_line(0, &line))
	{
		if (ft_strchr('-', line))
			
	}

	return (1);
}


int main(void)
{
	t_recurse *infos;

	lists_init(infos);
	
}
