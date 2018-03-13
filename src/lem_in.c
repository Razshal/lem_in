/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:37:42 by mfonteni          #+#    #+#             */
/*   Updated: 2018/03/13 15:15:11 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static int lem_init(int lem_amount, t_recurse *infos)
{
	if (!(infos->lem_list = (t_lem_list*)malloc(sizeof(t_lem_list) * 1)))
		
}

static int lists_init(t_recurse *infos)
{
	char *line;

	if (!(infos = (t_recurse*)malloc(sizeof(t_recurse) * 1)))
		return (0);
	get_next_line(0, &line);
	lem_init(ft_atoi(line), infos);
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
