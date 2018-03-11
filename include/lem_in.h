/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 12:50:37 by mfonteni          #+#    #+#             */
/*   Updated: 2018/03/11 14:17:43 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define SUCCESS -2
# define FAILURE -1
# define ENDOFTAB -2147483648
# define INTMAX 2147483647

typedef struct	s_room_list
{
	int room;
	int *links;
	t_room_list *next;
}				t_room_list

typdef struct	s_lem_list
{
	int lem;
	int room;
	t_lem_list *next;
}				t_lem_list

#endif
