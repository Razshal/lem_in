/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:21:34 by mfonteni          #+#    #+#             */
/*   Updated: 2018/03/16 18:03:14 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_memdel(void **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = NULL;
	}
}

void	ft_memdel_array(void ***ap)
{
	int count;

	count = 0;
	while (*ap && *ap[count])
	{
		free(*ap[count]);
		*ap[count++] = NULL;
	}
	free(*ap);
	*ap = NULL;
}
