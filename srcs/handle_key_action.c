/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_action.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 21:11:14 by jjaniec           #+#    #+#             */
/*   Updated: 2018/04/24 14:51:12 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	refresh_display(t_term_caps *tcaps)
{
	ft_putstr(tcaps->clear_s);
	print_args(tcaps, tcaps->e_infos.elems);
}

void	handle_key_bs(t_term_caps *tcaps)
{
	t_ft_select_arg	*tmp;

	tmp = tcaps->cursor_pos_ptr;
	if (tcaps->cursor_pos_ptr->next && tcaps->cursor_pos_ptr->prev)
	{
		tcaps->cursor_pos_ptr->next->prev = tcaps->cursor_pos_ptr->prev;
		tcaps->cursor_pos_ptr->prev->next = tcaps->cursor_pos_ptr->next;
		tcaps->cursor_pos_ptr = tcaps->cursor_pos_ptr->prev;
	}
	else if (tcaps->cursor_pos_ptr->next)
	{
		tcaps->cursor_pos_ptr = tcaps->cursor_pos_ptr->next;
		tcaps->cursor_pos_ptr->prev = NULL;
		tcaps->e_infos.elems = tcaps->cursor_pos_ptr;
		tcaps->e_infos.elems_first = tcaps->cursor_pos_ptr;
	}
	else if (tcaps->cursor_pos_ptr->prev)
	{
		tcaps->cursor_pos_ptr = tcaps->cursor_pos_ptr->prev;
		tcaps->cursor_pos_ptr->next = NULL;
		tcaps->e_infos.elems_last = tcaps->cursor_pos_ptr;
	}
	free(tmp);
	refresh_display(tcaps);

}

/*
** Handle escape key
*/

void	handle_escape(void)
{
	save_restore_term_settings(RESTORE);
	exit(EXIT_SUCCESS);
}
