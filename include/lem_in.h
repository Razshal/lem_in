/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 12:50:37 by mfonteni          #+#    #+#             */
/*   Updated: 2018/03/13 15:14:28 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

#ifndef LEM_IN_H
# define LEM_IN_H
# define SUCCESS -1
# define START -10
# define END -20
# define CLASSICROOM -30
# define INTMAX 2147483647
# define FAILURE INTMAX

typedef struct	s_room_list t_room_list;

typedef struct	s_room_links
{
	struct s_room_list	*room;
	struct s_room_links	*next;
}				t_room_links;

struct	s_room_list
{
	int					room_num;
	int					room_type;
	struct s_room_links	*linked_rooms;
	struct s_room_list	*next;
};

typedef struct	s_lem_list
{
	int					lem;
	int					room;
	struct s_lem_list	*next;
}				t_lem_list;

typedef struct	s_recurse
{
	t_room_list	*room_list;
	t_lem_list	*lem_list;
	t_room_list	*next_room;
}				t_recurse;

t_room_list		*get_room(int room, t_room_list *rlist);
t_room_list		*get_last_item(t_room_list *rlist);
t_room_links	*get_lroom_num(int room_num, int link_num, t_room_list *rlist);
t_room_links	*get_lroom_pos(int room_num, int link_num, t_room_list *rlist);
t_room_links	*get_last_item_link(t_room_links *rlink);
t_lem_list		*get_lem(int lem_num, t_lem_list *llist);
int				add_lem(int lem_num, int room_num, t_lem_list *llist);

#endif
