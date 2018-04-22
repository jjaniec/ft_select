/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 18:27:22 by jjaniec           #+#    #+#             */
/*   Updated: 2018/04/22 20:45:00 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
** Gets a arguments linked list and move of $move_pos elements
** in the linked list,
** if the index is inferior to 0, the pointer moves backward,
** or if the index is superior to 0, the pointer moves forward,
** if it get's out of the linked list, the function returns NULL, else
** return the pointer of the found element
*/

static void			move_cursor_next(t_term_caps *tcaps, t_ft_select_arg **ptr)
{
	if (ptr && *ptr)
	{
		if ((*ptr)->next)
			*ptr = (*ptr)->next;
		else
			*ptr = tcaps->e_infos.elems_first;
	}
}

static void			move_cursor_prev(t_term_caps *tcaps, t_ft_select_arg **ptr)
{
	if (ptr && *ptr)
	{
		if ((*ptr)->prev)
			*ptr = (*ptr)->prev;
		else
			*ptr = tcaps->e_infos.elems_last;
	}
}

t_ft_select_arg		*move_cursor_index(t_term_caps *tcaps, int move_pos, \
						t_ft_select_arg *args_ptr)
{
	t_ft_select_arg	*ptr;

	ptr = args_ptr;
	if (args_ptr && move_pos > 0)
		while (move_pos-- > 0 && ptr)
			move_cursor_next(tcaps, &ptr);
	else if (args_ptr && move_pos < 0)
		while (move_pos++ < 0 && ptr)
			move_cursor_prev(tcaps, &ptr);
	return (ptr);
}
