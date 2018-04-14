/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 12:50:37 by mfonteni          #+#    #+#             */
/*   Updated: 2018/04/14 15:22:21 by mfonteni         ###   ########.fr       */
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
	char				*name;
	int					type;
	struct s_room_links	*l_rooms;
	struct s_room_list	*next;
};

typedef struct	s_lem_list
{
	int					lem;
	char				*room;
	struct s_lem_list	*next;
}				t_lem_list;

typedef struct	s_recurse
{
	t_room_list	*room_list;
	t_lem_list	*lem_list;
	t_room_list	*next_room;
}				t_recurse;

t_room_list		*get_room(char *name, t_room_list *rlist);
t_room_list		*get_last_item(t_room_list *rlist);
t_room_links	*get_lroom_name(char *name, int link_num, t_room_list *rlist);
t_room_links	*get_lroom_pos(t_room_list *room, int link_num);
t_room_links	*get_last_item_link(t_room_links *rlink);
t_lem_list		*get_lem(int lem_num, t_lem_list *llist);
int				add_lem(int lem_num, char *room_name, t_lem_list **llist);
char			*get_start_name(t_room_list *room);
int				add_room(char *room_name, int room_type, t_room_list **rlist);
int				add_link(char *line, t_room_list *rlist);
int				is_end_room(char *room_name, t_room_list *list);
int				lists_init(t_recurse *infos);
void			delete_array(char **array);

//////////////// DEBUG ////////////////////
#define BUGERROR ft_printf("{RED}BUGERROR{EOC}\n")
#define ERROR(message) ft_printf("{RED}%s{EOC}\n", message)
#define SUCCESSM(message) ft_printf("{GREEN}%s{EOC}\n", message)
#define INFO(message) ft_printf("{BLUE}%s{EOC}\n", message)
#include <stdio.h>
void print_struct(t_recurse *recurse);
int print_lem_struct(t_lem_list *list);
///////////////////////////////////////////

#endif
