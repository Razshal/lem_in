/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:02:38 by mfonteni          #+#    #+#             */
/*   Updated: 2018/05/03 12:58:35 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_str_isdigit(char *str)
{
	int count;

	count = 0;
	while (str[count])
	{
		if (!ft_isdigit(str[count]) && str[count] != ' ')
			return (0);
		count++;
	}
	return (1);
}

int	ft_str_is_stricly_digit(char *str)
{
	int count;

	count = 0;
	while (str[count])
	{
		if (!ft_isdigit(str[count]))
			return (0);
		count++;
	}
	return (1);
}
