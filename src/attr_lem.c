/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attr_lem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:12:56 by abouvero          #+#    #+#             */
/*   Updated: 2018/04/26 15:26:55 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int     decal_lem(t_attr_paths **tab, int len)
{
    int     i;
    int     done;

    i = -1;
    done = 0;
    while (++i < len - 1)
    {
        if ((*tab)[i].lem_nbr > (*tab)[i + 1].lem_nbr + 1)
        {
            i = -1;
            (*tab)[i].lem_nbr -= 1;
            (*tab)[i + 1].lem_nbr += 1;
            done = 1;
        }
    }
    return (done ? 1 : 0);
}

int     get_comb(t_attr_paths *tab, int len, int min)
{
    int     i;

    i = -1;
    while (++i < len)
        tab[i].total_length = tab[i].path_length + tab[i].lem_nbr - 1;
	while (i >= 0)
	{
		--i;
		if (tab[i].lem_nbr)
			break;
	}
    if (tab[i].total_length - tab[0].total_length > min)
        return (-1);
    else
        return (tab[i].total_length - tab[0].total_length);
}

void    init_path_tab(t_attr_paths **tab, t_lem_list *lem, int lem_nbr, int len)
{
    int     i;

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

void    print_tabss(t_attr_paths *tab, int len, int min)
{
    int     i = -1;

    ft_printf("MIN : %d\n", min);
    while (++i < len)
        ft_printf("PATH_LEN : %d | LEM_NBR : %d | TOTAL_LEN : %d\n", tab[i].path_length, tab[i].lem_nbr, tab[i].total_length);
}

void    calc_lems_by_path(t_lem_list *lem, int lem_nbr, int path_nbr)
{
    t_attr_paths    *tab;
    int             min;

    min = INTMAX;
    if (!(tab = (t_attr_paths*)malloc(sizeof(t_attr_paths) * path_nbr)))
        return ;
    init_path_tab(&tab, lem, lem_nbr, path_nbr);
    while ((min = get_comb(tab, path_nbr, min)) != -1)
    {
        print_tabss(tab,path_nbr, min);
        //ft_printf("MIN : %d\n", min);
        if (!decal_lem(&tab, path_nbr))
            break;
    }
    //free_tab();
}