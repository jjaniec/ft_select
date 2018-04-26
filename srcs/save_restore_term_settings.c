/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_restore_term_settings.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 21:18:43 by jjaniec           #+#    #+#             */
/*   Updated: 2018/04/24 15:34:21 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
** The 'mode' parameter can be SAVE or RESTORE.
** SAVE : the function saves the current terminal settings
** RESTORE : the function restores the settings previously
** saved (see SAVE mode)
*/

void		save_restore_term_settings(int mode)
{
	static struct termios	orig_tios;

	if (mode == SAVE)
	{
		if (tcgetattr(STDIN_FILENO, &orig_tios) == -1)
			ft_exit(FATAL_ERROR, "Call to tcgetattr() failed\n");
	}
	else if (mode == RESTORE || mode == RESTORE_NO_SCR_END)
	{
		if (mode != RESTORE_NO_SCR_END)
		{
			ft_putstr(tgetstr("ve", NULL));
			ft_putstr(END_SCR);
		}
		if (tcsetattr(STDIN_FILENO, TCSANOW, &orig_tios) == -1)
			ft_exit(FATAL_ERROR, \
				"Failure while restoring the originals settings (tcsetattr() failed)\n");
	}
}
