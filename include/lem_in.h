/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 12:50:37 by mfonteni          #+#    #+#             */
/*   Updated: 2018/03/12 18:31:00 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

#ifndef LEM_IN_H
# define LEM_IN_H
# define SUCCESS -2
# define FAILURE -1
# define START -10
# define END -20
# define CLASSICROOM -30
# define ENDOFTAB -2147483648
# define INTMAX 2147483647

typedef struct	s_room_list t_room_list;

typedef struct	s_room_links
{
	struct s_room_list	*room;
	struct s_room_links	*next;
}				t_room_links;

struct	s_room_list
{
	int					room_number;
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
	int			room;
}				t_recurse;

t_room_list *get_room(int room, t_room_list *rlist);
t_room_list *get_last_item(t_room_list *rlist);

#endif
