/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:09:25 by mfonteni          #+#    #+#             */
/*   Updated: 2018/03/21 15:22:47 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	delete_array(char **array)
{
	int count;

	count = 0;
	if (array)
		while (array[count])
			ft_memdel((void**)&array[count++]);
	ft_memdel((void**)array);
}
