/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 18:27:22 by jjaniec           #+#    #+#             */
/*   Updated: 2018/04/25 18:50:43 by jjaniec          ###   ########.fr       */
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

static t_ft_select_arg		*move_cursor_next(t_term_caps *tcaps, \
							t_ft_select_arg *ptr, bool round_)
{
	if (ptr)
	{
		if (ptr->next)
			return (ptr->next);
		else if (round_ == true)
			return (tcaps->e_infos.elems_first);
		else
			return (NULL);
	}
	return (ptr);
}

static t_ft_select_arg		*move_cursor_prev(t_term_caps *tcaps, \
							t_ft_select_arg *ptr, bool round_)
{
	if (ptr)
	{
		if (ptr->prev)
			return (ptr->prev);
		else if (round_ == true)
			return (tcaps->e_infos.elems_last);
		else
			return (NULL);
	}
	return (ptr);
}

static t_ft_select_arg		*move_up_first_row(t_term_caps *tcaps, \
								t_ft_select_arg *args_ptr)
{
	unsigned int	last_pos_mod;
	t_ft_select_arg	*ptr;

	ptr = tcaps->e_infos.elems_last;
	last_pos_mod = args_ptr->index;
	if (last_pos_mod == tcaps->e_infos.elems_per_row)
		last_pos_mod = 0;
	while (ptr && ptr->prev && \
		(ptr->index % tcaps->e_infos.elems_per_row) != last_pos_mod)
		ptr = ptr->prev;
	return (ptr);
}

t_ft_select_arg				*move_cursor_index(t_term_caps *tcaps, \
								int move_count, t_ft_select_arg *args_ptr, \
								int stop_at_null)
{
	t_ft_select_arg	*ptr;
	int				move_pos;

	move_pos = move_count;
	ptr = args_ptr;
	if (stop_at_null == false && move_count > 1 && \
		move_cursor_index(tcaps, move_count, args_ptr, true) == NULL)
		return (move_cursor_index(tcaps, \
			((args_ptr->index - 1) % tcaps->e_infos.elems_per_row), \
			tcaps->e_infos.elems_first, false));
	else if (stop_at_null == false && move_count < -1 && \
		args_ptr->index <= tcaps->e_infos.elems_per_row)
		return (move_up_first_row(tcaps, args_ptr));
	if (args_ptr && move_pos > 0)
		while (move_pos-- > 0 && ptr)
			ptr = move_cursor_next(tcaps, ptr, !stop_at_null);
	else if (args_ptr && move_pos < 0)
		while (move_pos++ < 0 && ptr)
			ptr = move_cursor_prev(tcaps, ptr, !stop_at_null);
	return (ptr);
}
