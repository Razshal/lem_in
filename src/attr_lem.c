/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attr_lem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:12:56 by abouvero          #+#    #+#             */
/*   Updated: 2018/04/26 18:47:28 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void	free_unused_paths(t_attr_paths *tab, int len)
{
	int		i;

	i = -1;
	while (++i <len)
		if (!tab[i].lem_nbr)
			recfr_path(tab[i].path);
}

void    init_path_tab(t_attr_paths **tab, t_lem_list *lem, int lem_nbr, int len)
{
	int		i;

	i = -1;
	while (++i < len)
	{
    	(*tab)[i].path_length = lem->path->length;
    	(*tab)[i].lem_nbr = 0;
    	(*tab)[i].path = lem->path;
    	(*tab)[i].total_length = 0;
    	lem = lem->next;
	}
	(*tab)[0].lem_nbr = lem_nbr;
}

int				get_score(t_attr_paths **tab, int len, int min)
{
	int		i;
	int		score;

	i = -1;
	score = INTMAX;
	while (++i < len && (*tab)[i].lem_nbr)
		(*tab)[i].total_length = (*tab)[i].path->length + (*tab)[i].lem_nbr;
	score = (*tab)[i - 1].total_length - (*tab)[0].total_length;
	//ft_printf("SCORE : %d | MIN :%d\n", score, min);
	return (score < min ? score : -1);
}

int				decal_lem(t_attr_paths **tab, int len)
{
	int		i;
	int		done;

	i = -1;
	done = 0;
	while (++i < len - 1)
	{
		if ((*tab)[i].lem_nbr > (*tab)[i + 1].lem_nbr + ((*tab)[i].path->length == (*tab)[i + 1].path->length ? 0 : 1))
		{
			(*tab)[i].lem_nbr -= 1;
			(*tab)[i + 1].lem_nbr += 1;
			i = -1;
			done = 1;
		}
	}
	return (done ? 1 : 0);
}

t_attr_paths	*calc_lems_by_path(t_lem_list *lem, int lem_nbr, int len)
{
    t_attr_paths    *tab;
	int				min;

	min = INTMAX;
    if (!(tab = (t_attr_paths*)malloc(sizeof(t_attr_paths) * len)))
        return (NULL);
    init_path_tab(&tab, lem, lem_nbr, len);
	while ((min = get_score(&tab, len, min)) != -1)
		if (decal_lem(&tab, len))
		{
			//INFO("BREAK IN DECAL");
			break;
		}
	//INFO("CALC_LEM DONE");
	//print_tabss(tab, len, min);
	//free_unused_paths(tab, len);
    return (tab);
}