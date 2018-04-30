/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 16:14:42 by cyfermie          #+#    #+#             */
/*   Updated: 2018/04/26 20:44:42 by jjaniec          ###   ########.fr       */
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
		tcaps->cursor_pos_ptr = move_cursor_index(tcaps, \
			-(tcaps->e_infos.elems_per_row), tcaps->cursor_pos_ptr, false);
		refresh_display(tcaps);
	}
	else if (is_key_down_arrow(key) == true)
	{
		tcaps->cursor_pos_ptr = move_cursor_index(tcaps, \
			tcaps->e_infos.elems_per_row, tcaps->cursor_pos_ptr, false);
		refresh_display(tcaps);
	}
	else if (is_key_left_arrow(key) == true)
	{
		tcaps->cursor_pos_ptr = \
			move_cursor_index(tcaps, -1, tcaps->cursor_pos_ptr, false);
		refresh_display(tcaps);
	}
	else if (is_key_right_arrow(key) == true)
	{
		tcaps->cursor_pos_ptr = \
			move_cursor_index(tcaps, 1, tcaps->cursor_pos_ptr, false);
		refresh_display(tcaps);
	}
}

void		analyze_key(t_term_caps *tcaps, char key[SZBUFKEY])
{
	if (key[0] == KEY_ESCAPE && key[1] == '\0')
		handle_escape(tcaps);
	else if (key[0] == KEY_SPACE && key[1] == '\0')
	{
		tcaps->cursor_pos_ptr->selected = !tcaps->cursor_pos_ptr->selected;
		tcaps->cursor_pos_ptr = \
			move_cursor_index(tcaps, 1, tcaps->cursor_pos_ptr, false);
		refresh_display(tcaps);
	}
	else if ((key[0] == KEY_BS && key[1] == '\0') || is_key_delete(key))
	{
		handle_key_bs(tcaps);
		get_printing_width(&(tcaps->e_infos), tcaps->e_infos.elems);
		refresh_display(tcaps);
	}
	else if (key[0] == KEY_RETURN && key[1] == '\0')
		handle_key_return(tcaps);
	else
		analyze_key_arrow(tcaps, key);
}
