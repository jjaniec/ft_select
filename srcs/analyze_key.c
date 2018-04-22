/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 16:14:42 by cyfermie          #+#    #+#             */
/*   Updated: 2018/04/22 21:18:59 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
**	Launch the function linked to the parameter 'key'.
**	If no function is linked to the key, it does nothing.
**	Keys recognized : up/down/left/right arrows -
**	escape - space - backspace - delete - return.
*/

static void	analyze_key_arrow(t_term_caps *tcaps, char key[SZBUFKEY])
{
	if (is_key_up_arrow(key) == true)
	{
		tcaps->cursor_pos_ptr = move_cursor_index(tcaps, -(tcaps->e_infos.elems_per_row), tcaps->cursor_pos_ptr);
		ft_putstr(tcaps->clear_s);
		print_args(tcaps, tcaps->e_infos.elems);
	}
	else if (is_key_down_arrow(key) == true)
	{
		tcaps->cursor_pos_ptr = move_cursor_index(tcaps, tcaps->e_infos.elems_per_row, tcaps->cursor_pos_ptr);
		ft_putstr(tcaps->clear_s);
		print_args(tcaps, tcaps->e_infos.elems);
	}
	else if (is_key_left_arrow(key) == true)
	{
		tcaps->cursor_pos_ptr = move_cursor_index(tcaps, -1, tcaps->cursor_pos_ptr);
		ft_putstr(tcaps->clear_s);
		print_args(tcaps, tcaps->e_infos.elems);
	}
	else if (is_key_right_arrow(key) == true)
	{
		tcaps->cursor_pos_ptr = move_cursor_index(tcaps, 1, tcaps->cursor_pos_ptr);
		ft_putstr(tcaps->clear_s);
		print_args(tcaps, tcaps->e_infos.elems);
	}
}

void		analyze_key(t_term_caps *tcaps, char key[SZBUFKEY])
{
	t_ft_select_arg	*new_next;
	if (key[0] == KEY_ESCAPE && key[1] == '\0')
	{
		handle_escape();
	}
	else if (key[0] == KEY_SPACE && key[1] == '\0')
	{
		tcaps->cursor_pos_ptr->selected = !tcaps->cursor_pos_ptr->selected;
		tcaps->cursor_pos_ptr = move_cursor_index(tcaps, 1, tcaps->cursor_pos_ptr);
		ft_putstr(tcaps->clear_s);
		print_args(tcaps, tcaps->e_infos.elems);
	}
	else if ((key[0] == KEY_BS && key[1] == '\0') || is_key_delete(key))
	{

	}
	else if (key[0] == KEY_RETURN && key[1] == '\0')
	{

	}
	else
		analyze_key_arrow(tcaps, key);
}
