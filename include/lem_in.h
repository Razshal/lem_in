/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 12:50:37 by mfonteni          #+#    #+#             */
/*   Updated: 2018/04/26 13:35:23 by mfonteni         ###   ########.fr       */
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

typedef struct	s_coord
{
	int					x;
	int					y;
}				t_coord;

typedef struct	s_map
{
	char				*str;
	struct s_map		*next;
}				t_map;

struct	s_room_list
{
	char				*name;
	int					type;
	int 				occupied;
	int 				weight;
	int 				traffic;
	int					number_of_links;
	t_coord				coords;
	struct s_room_links	*l_rooms;
	struct s_room_list	*next;
};

typedef struct	s_lem_list
{
	int					lem;
	char				*room;
	int 				arrived;
	struct s_path 		*path;
	struct s_path 		*beg_path;
	struct s_lem_list	*next;
}				t_lem_list;

typedef struct	s_recurse
{
	t_room_list	*room_list;
	t_lem_list	*lem_list;
	t_room_list	*next_room;
	char		*line;
}				t_recurse;

typedef struct   s_path
{
	t_room_list 	*room;
	int 			length;
	struct s_path 	*next;
}				t_path;

t_room_list		*get_room(char *name, t_recurse *infos);
t_room_list		*get_last_item(t_room_list *rlist);
t_room_links	*get_lroom_name(char *name, int link_num, t_room_list *rlist);
t_room_links	*get_lroom_pos(t_room_list *room, int link_num);
t_room_links	*get_last_item_link(t_room_links *rlink);
t_lem_list		*get_lem(int lem_num, t_recurse *infos);
int				add_lem(int lem_num, char *room_name, t_recurse *infos);
char			*get_start_name(t_room_list *room);
int				add_room(char *room_name, int roomtype,
t_coord coords, t_recurse *infos);
int				add_link(char *line, t_recurse *infos);
int				is_end_room(char *room_name, t_recurse *infos);
int				lists_init(t_recurse **infos, t_map **map);
void			delete_array(char **array);
int				delete_struct(t_recurse *infos);
t_path			*get_path(t_room_list *rl);
void			moove_lems(t_lem_list *lem, t_room_list *rl);
int				append_line(char *str, t_map **map);
int				display_map(t_map *map);

//////////////// DEBUG ////////////////////
#define BUGERROR			ft_printf("{RED}BUGERROR{EOC}\n")
#define ERROR(message)		ft_printf("{RED}%s{EOC}\n", message)
#define SUCCESSM(message)	ft_printf("{GREEN}%s{EOC}\n", message)
#define INFO(message)		ft_printf("{BLUE}%s{EOC}\n", message)
#include <stdio.h>
void print_struct(t_recurse *recurse);
int print_lem_struct(t_lem_list *list);
///////////////////////////////////////////

#endif
