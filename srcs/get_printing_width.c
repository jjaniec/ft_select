/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_printing_width.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 19:43:16 by jjaniec           #+#    #+#             */
/*   Updated: 2018/04/20 19:57:36 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
** Cycle through a char ** to find the lenght of the largest element,
** Return -1 if passed char ** is NULL or has a lenght of 0
*/

int		get_printing_width(t_elems_infos *e_infos, char **elems)
{
	int		x;
	int		i;

	i = -1;
	if (!elems || (elems && !(elems[0])))
		return (-1);
	while (elems[++i])
	{
		x = ft_strlen(elems[i]);
		if ((x - 2) > e_infos->width)
			e_infos->width = x + 2;
	}
	return (0);
}
