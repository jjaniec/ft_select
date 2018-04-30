/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_printing_width.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 19:43:16 by jjaniec           #+#    #+#             */
/*   Updated: 2018/04/21 21:31:23 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
** Cycle through a char ** to find the lenght of the largest element,
** Return -1 if passed char ** is NULL or has a lenght of 0
*/

int		get_printing_width(t_elems_infos *e_infos, t_ft_select_arg *elems)
{
	int		len;

	e_infos->width = 0;
	if (elems == NULL)
		return (-1);
	while (elems != NULL)
	{
		len = ft_strlen(elems->str);
		if (len > e_infos->width)
			e_infos->width = len;
		elems = elems->next;
	}
	return (0);
}
