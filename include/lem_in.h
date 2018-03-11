/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 12:50:37 by mfonteni          #+#    #+#             */
/*   Updated: 2018/03/11 17:12:37 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

#ifndef LEM_IN_H
# define LEM_IN_H
# define SUCCESS -2
# define FAILURE -1
# define START -10
# define END -20
# define ENDOFTAB -2147483648
# define INTMAX 2147483647

typedef struct	s_room_list
{
	int					room;
	int					roomtype;
	int					*links;
	struct s_room_list	*next;
}				t_room_list;

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


#endif
