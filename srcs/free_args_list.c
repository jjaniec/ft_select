/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_args_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 18:38:58 by jjaniec           #+#    #+#             */
/*   Updated: 2018/04/21 18:40:55 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
** Frees created linked list to sort cli arguments
*/

void		free_args_list(t_ft_select_arg *li)
{
	t_ft_select_arg	*prev;

	while (li)
	{
		prev = li;
		li = li->next;
		free(prev);
	}
}