/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_action.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 21:11:14 by jjaniec           #+#    #+#             */
/*   Updated: 2018/04/26 20:44:45 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	refresh_display(t_term_caps *tcaps)
{
	ft_putstr_fd(tcaps->clear_s, STDIN_FILENO);
	print_args(tcaps, tcaps->e_infos.elems);
}

void	handle_key_return(t_term_caps *tcaps)
{
	t_ft_select_arg	*ptr;

	ptr = tcaps->e_infos.elems;
	ft_putstr_fd(END_SCR, STDIN_FILENO);
	while (ptr)
	{
		if (ptr->selected == true)
			ft_dprintf(STDOUT_FILENO, "%s ", ptr->str);
		ptr = ptr->next;
	}
	save_restore_term_settings(RESTORE_NO_SCR_END);
	free_args_list(tcaps->e_infos.elems);
	exit(EXIT_SUCCESS);
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
	else
		return (handle_escape(tcaps));
	free(tmp);
}

/*
** Handle escape key
*/

void	handle_escape(t_term_caps *tcaps)
{
	free_args_list(tcaps->e_infos.elems);
	save_restore_term_settings(RESTORE);
	exit(EXIT_SUCCESS);
}
