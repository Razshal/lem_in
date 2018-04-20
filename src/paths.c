/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 12:24:57 by abouvero          #+#    #+#             */
/*   Updated: 2018/04/18 16:35:17 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

//////////////////////////////////////////////////////////////////////////////////////////

void    print_tab(t_weight *wtab, int len)
{
    int i = -1;
    while (++i < len)
        ft_printf("%s %d %d\n", wtab[i].name, wtab[i].weight, wtab[i].done);
}

void	print_path(t_path *path)
{
	while (path)
	{
		ft_printf("%s", path->room->name);
		path->next ? ft_printf(" -> ") : ft_printf("\n");
		path = path->next;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////

void 	free_tabs(t_weight *wtab, t_father *ftab, int len)
{
	int 	i;

	i = -1;
	while (++i < len)
		ft_memdel((void**)&wtab[i].name);
	i = -1;
	while (++i < len)
	{
		ft_memdel((void**)&ftab[i].name);
		ft_memdel((void**)&ftab[i].father);
	}
	ft_memdel((void**)&wtab);
	ft_memdel((void**)&ftab);
}

/////////////////////////////////////////////////////////////////////////////////////////

int		ft_list_length(t_room_list *list)
{
	return (list == NULL ? 0 : 1 + ft_list_length(list->next));
}

t_room_list *get_room_addr(t_room_list *rl, char *name)
{
	while (rl)
	{
		if (!ft_strcmp(rl->name, name))
			return (rl);
		rl = rl->next;
	}
    return (NULL);
}

char	*last_rname(t_path *path)
{
	if (!path)
		return (NULL); // SEGV
	while (path->next)
		path = path->next;
	return (path->room->name);
}

t_path	*create_path(t_path *path, t_room_list *room)
{
	t_path	*new;
    t_path  *beg;

	if (!(new = (t_path*)malloc(sizeof(t_path))))
		return (NULL);
	new->next = NULL;
	new->room = room;
	new->occupied = 0;
    beg = path;
	if (!path)
		return (new);
	while (path->next)
		path = path->next;
	path->next = new;
	return (beg);
}

t_path	*get_path(t_father *ftab, t_room_list *rl, int len, char *end_name)
{
    int i = -1;
    t_path 	*path;
    t_room_list *room;

    path = NULL;
    while (++i < len)
    {
        print_path(path);
    	if (ftab[i].father == NULL && path == NULL)
    	{
    		path = create_path(path, get_room_addr(rl, ftab[i].name));
    		i = -1;
    	}
    	else if (path != NULL && ftab[i].father != NULL &&  ft_strcmp(ftab[i].father, last_rname(path)) == 0)
    	{
            if ((room = get_room_addr(rl, ftab[i].name))->number_of_links > 1 || !ft_strcmp(room->name, end_name))
            {
    		    path = create_path(path, room);
    		    i = -1;
            }
    	}
    }
    return (path);
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

//////////////////////////////////////////////////////////////////////////////////////////////////////

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
    return (endn);
}

t_path   *solver(t_room_list *rl)
{
    t_weight    *wtab;
    t_father    *ftab;
    t_path		*path;
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
    path = get_path(ftab, rl, len, end_name);
    SUCCESSM("PATHDONE");
    free_tabs(wtab, ftab, len);
    print_path(path);
    return (path);
}

//Si plusieurs father = NULL, get_path prend le premier du coup rip
//Si plusieurs meme fils pareil