/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 12:50:37 by mfonteni          #+#    #+#             */
/*   Updated: 2018/05/02 17:25:14 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/includes/libft.h"
# define START -10
# define END -20
# define CLASSICROOM -30
# define INTMAX 2147483647

typedef struct s_room_list	t_room_list;

typedef struct	s_room_links
{
	struct s_room_list	*room;
	struct s_room_links	*next;
}							t_room_links;

typedef struct	s_map
{
	char				*str;
	struct s_map		*next;
}							t_map;

struct	s_room_list
{
	char				*name;
	int					type;
	int					occupied;
	int					weight;
	int					traffic;
	int					number_of_links;
	struct s_room_links	*l_rooms;
	struct s_room_list	*next;
};

typedef struct	s_lem_list
{
	int					lem;
	char				*room;
	int					arrived;
	struct s_path		*path;
	struct s_lem_list	*next;
}							t_lem_list;

typedef struct	s_recurse
{
	t_room_list	*room_list;
	t_lem_list	*lem_list;
	t_room_list	*next_room;
	char		*line;
}							t_recurse;

typedef struct	s_path
{
	t_room_list		*room;
	int				length;
	struct s_path	*next;
}							t_path;

typedef struct	s_attr_paths
{
	int				path_length;
	int				lem_nbr;
	int				total_length;
	struct s_path	*path;
}							t_attr_paths;

t_room_list					*get_room(char *name, t_recurse *infos);
t_lem_list					*get_lem(int lem_num, t_recurse *infos);
int							add_lem(int lem_num, char *room_name, t_recurse *infos);
int							add_room(char *room_name, int roomtype, t_recurse *infos);
int							add_link(char *line, t_recurse *infos);
int							is_end_room(char *room_name, t_recurse *infos);
int							lists_init(t_recurse **infos, t_map **map);
void						delete_struct(t_recurse *infos);
t_path						*get_path(t_room_list *rl);
int							moove_lems(t_lem_list *lem, t_room_list *rl, t_map *map);
t_attr_paths				*calc_lems_by_path(t_lem_list *lem, int lem_nbr, int path_nbr);
int							append_line(char *str, t_map **map);
int							display_map(t_map *map);
void						free_map(t_map **map);
void						recfr_path(t_path *path);
t_path						*last(t_path *path);
t_room_list					*get_min_addr(t_room_links *links);
int							get_min(t_room_links *rl);
int							initialized(t_room_links *links);
void						restart_weight(t_room_list *rl);
void						free_paths(t_attr_paths *tab, int len);
int							all_arrived(t_lem_list *lem);
int							get_diff_path(t_lem_list *lem, t_room_list *rl);
int							get_path_nbr(t_lem_list *lem);
t_room_list					*get_start(t_room_list *rl);

#endif
