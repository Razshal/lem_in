/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noleaks_get_next_line.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 18:05:09 by mfonteni          #+#    #+#             */
/*   Updated: 2018/03/21 16:39:24 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	noleaks_get_next_line(int fd, char **line)
{
	ft_memdel((void**)&*line);
	return (get_next_line(fd, line));
}
