/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:09:25 by mfonteni          #+#    #+#             */
/*   Updated: 2018/04/26 14:57:26 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void		delete_array(char **array)
{
	int count;

	count = 0;
	if (array)
		while (array[count])
			free(array[count++]);
	free(array);
}

static void	free_rl_links(t_room_links *rl_l)
{
	if (!rl_l)
		return ;
	if (rl_l->next)
		free_rl_links(rl_l->next);
	ft_memdel((void**)&rl_l);
}

static void	free_rl(t_room_list *rl)
{
	if (rl->next)
		free_rl(rl->next);
	free_rl_links(rl->l_rooms);
	ft_memdel((void**)&rl->name);
	ft_memdel((void**)&rl);
}

static void	free_lems(t_lem_list *lems)
{
	if (lems->next)
		free_lems(lems->next);
	ft_memdel((void**)&lems->room);
	ft_memdel((void**)&lems);
}

int			delete_struct(t_recurse *rec)
{
	if (rec->lem_list)
		free_lems(rec->lem_list);
	free_rl(rec->room_list);
	ft_memdel((void**)&rec);
	return (0);
}
