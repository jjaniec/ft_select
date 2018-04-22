/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 18:27:22 by jjaniec           #+#    #+#             */
/*   Updated: 2018/04/22 18:55:56 by jjaniec          ###   ########.fr       */
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

static void			move_cursor_next(t_ft_select_arg **ptr)
{
	if (ptr && *ptr)
		*ptr = (*ptr)->next;
}

static void			move_cursor_prev(t_ft_select_arg **ptr)
{
	if (ptr && *ptr)
		*ptr = (*ptr)->prev;
}

t_ft_select_arg		*move_cursor_index(int move_pos, t_ft_select_arg *args_ptr)
{
	t_ft_select_arg	*ptr;

	ptr = args_ptr;
	if (args_ptr && move_pos > 0)
		while (move_pos-- > 0 && ptr)
			move_cursor_next(&ptr);
	else if (args_ptr && move_pos < 0)
		while (move_pos++ < 0 && ptr)
			move_cursor_prev(&ptr);
	return (ptr);
}
