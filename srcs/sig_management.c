/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 19:25:02 by cyfermie          #+#    #+#             */
/*   Updated: 2018/04/24 15:34:57 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

extern t_term_caps 		*g_tcaps;

static void		handle_sigint(int sig)
{
	save_restore_term_settings(RESTORE);
	exit(sig);
}

static void		handle_sigwinch(int sig)
{
	(void)sig;
	ft_putstr(g_tcaps->clear_s);
	get_term_size(&(g_tcaps->ts));
	print_escape_msg();
	print_args(g_tcaps, g_tcaps->e_infos.elems);
}

/*
**	Initialize the functions for handling signals.
**	If an error occurs, returns -1 or 0 otherwise.
*/

int				init_sig_handlers(void)
{
	if (signal(SIGINT, &(handle_sigint)) == SIG_ERR)
		return (-1);
	if (signal(SIGWINCH, &(handle_sigwinch)) == SIG_ERR)
		return (-1);
	return (0);
}
