#include "../includes/lem_in.h"

t_path 		*last(t_path *path)
{
	while (path->next)
		path = path->next;
	return (path->room);
}

t_room_list *get_min_addr(t_room_links *links)
{
	int 	min;
	t_room_list *room;

	min = INTMAX;
	room = NULL;
	while (links)
	{
		if (links->room->weight < min)
		{
			min = links->room->weight;
			room = links->room;
		}
		links = links->next;
	}
	return (room);
}

int 	get_min(t_room_links *rl)
{
	int 	min;

	min = INTMAX;
	while (rl)
	{
		min = rl->room->weight != -1 && rl->room->weight < min ? rl->room->weight : min;
		rl = rl->next;
	}
	return (min);
}

void 	init_weight(t_room_list *rl)
{
	t_room_list *beg;
	int 		end_done;

	beg = rl;
	end_done = 0;
	while (rl && !end_done)
	{
		if (!end_done && rl->type == END)
		{
			rl->weight = 0;
			rl = beg;
			end_done = 1;
		}
		else if (end_done && rl->weight == -1 && rl->type != START)
		{
			rl->weight = get_min(rl->l_rooms) + 1;
			rl = beg;
		}
		rl = rl->next;
	}
}

t_path	*add_path(t_path *path, t_room_list *room)
{
	t_path	*new;
    t_path  *beg;

	if (!(new = (t_path*)malloc(sizeof(t_path))))
		return (NULL);
	new->next = NULL;
	new->room = room;
    beg = path;
	if (!path)
		return (new);
	while (path->next)
		path = path->next;
	path->next = new;
	return (beg);
}

t_path 	*solve_path(t_room_list *rl, t_path *path, int traffic)
{
	t_room_links *links;

	path = add_path(path, rl);
	while (last(path)->room->type != END)
	{
		links = path->room->l_rooms;
		path = add_path(path, get_min_addr(links))
	}
	return (path);
}

t_room_list	*get_start(t_room_list *rl)
{
	while (rl)
	{
		if (rl->type == START)
			return (rl);
		rl = rl->next;
	}
	return (NULL);
}

t_path	*get_path(t_room_list *rl)
{
	t_path *path;

	path = NULL;
	init_weight(rl);
	return (solve_path(get_start(rl), path, 0));
}