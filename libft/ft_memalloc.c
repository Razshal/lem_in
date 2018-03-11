/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:58:24 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/15 14:53:02 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void			*alloc;
	unsigned int	count;

	count = 0;
	if ((alloc = (void*)malloc(sizeof(void) * size)) != NULL)
	{
		while (count < size)
		{
			((int*)alloc)[count] = 0;
			count++;
		}
		return (alloc);
	}
	else
		return (NULL);
}
