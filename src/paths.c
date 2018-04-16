/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 12:24:57 by abouvero          #+#    #+#             */
/*   Updated: 2018/04/16 12:25:01 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

typedef struct  s_weight
{
    char            *name;
    t_room_links    *l_rooms;
    int             weight;
    int             done;
}               t_weight;

typedef struct  s_father
{
    char    *name;
    char    *father;
}               t_father;

int		ft_list_length(t_room_list *list)
{
	return (list == NULL ? 0 : 1 + ft_list_length(list->next));
}

void    read_ftab(t_father *ftab, int len, t_weight *wtab)
{
    (void)ftab;
    (void)len;
    (void)wtab;
}

void    print_tab(t_weight *wtab, int len)
{
    int i = -1;
    while (++i < len)
        ft_printf("%s %d %d\n", wtab[i].name, wtab[i].weight, wtab[i].done);
}

int     get_index(char *n, t_weight *wtab, int len)
{
    int     i;

    i = -1;
    while (++i < len)
        if (!ft_strcmp(n, wtab[i].name))
            return (i);
    return (-1); // SEGV SI IL TROUVE PAS;
}

int     get_min(t_weight *wtab, int len)
{
    int     i;
    int     min;

    i = -1;
    min = INTMAX;
    while (++i < len)
        min = wtab[i].weight > -1 && wtab[i].weight < min && !wtab[i].done ? i : min;
    return (min == INTMAX ? -1 : min);
}

int     solve(t_weight **wtab, t_father **ftab, char *end, int len)
{
    int     i;
    int     min;
    t_room_links    *rl;
    int     son_index;

    i = -1;
    if ((min = get_min(*wtab, len)) == -1) //Recupere l'index dans le tableau de la room ou le poid est le plus faible
        return (0);
    while (ft_strcmp(end, (*wtab)[min].name))
    {
        (*wtab)[min].done = 1;
        rl = (*wtab)[min].l_rooms;
        while (rl)
        {
            son_index = get_index(rl->room->name, *wtab, len); //Recupere l'index dans le tableau du nom correspondant a la room
            if (!(*wtab)[son_index].done)
            {
                if ((*wtab)[min].weight + 1 < (*wtab)[son_index].weight || (*wtab)[son_index].weight == -1)
                {
                    (*wtab)[son_index].weight = (*wtab)[min].weight + 1;
                    (*ftab)[son_index].father = ft_strdup((*wtab)[min].name);
                }
            }
            rl = rl->next;
        }
        min = get_min(*wtab, len);
        //print_tab(*wtab, len);
    }
    return (1);
}

char*   init_solver(t_room_list *rl, t_weight **wtab, t_father **ftab, int len)
{
    int     c;
    char    *endn;

    c = 0;
    endn = NULL;
    if (!(*wtab = (t_weight*)malloc(sizeof(t_weight) * len)))
        return (NULL);
    if (!(*ftab = (t_father*)malloc(sizeof(t_father) * len)))
        return (NULL);
    while (rl)
    {
        (*wtab)[c].name = ft_strdup(rl->name);
        (*wtab)[c].weight = rl->type == START ? 0 : -1;
        (*wtab)[c].l_rooms = rl->l_rooms;
        (*wtab)[c].done = 0;
        (*ftab)[c].name = ft_strdup(rl->name);
        endn = rl->type == END ? ft_strdup(rl->name) : endn;
        (*ftab)[c++].father = NULL;
        rl = rl->next;
    }
    //print_tab(wtab, len);
    return (endn);
}

int     solver(t_room_list *rl)
{
    t_weight    *wtab;
    t_father    *ftab;
    char        *end_name;
    int         len;

    wtab = NULL;
    ftab = NULL;
    len  = ft_list_length(rl);
    if (!(end_name = init_solver(rl, &wtab, &ftab, len)))
        return (0);
    INFO("INITDONE");
    solve(&wtab, &ftab, end_name, len);
    SUCCESSM("SOLVERDONE");
    //read_ftab(ftab, len, wtab);
    //return (get_path(ftab));
    return (0);
}