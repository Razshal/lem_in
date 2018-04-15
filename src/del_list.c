/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:09:25 by mfonteni          #+#    #+#             */
/*   Updated: 2018/04/15 15:30:15 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void	delete_array(char **array)
{
	int count;

	count = 0;
	if (array)
		while (array[count])
			free(array[count++]);
	free(array);
}
