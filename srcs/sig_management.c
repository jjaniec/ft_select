/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 19:25:02 by cyfermie          #+#    #+#             */
/*   Updated: 2018/04/20 19:25:03 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static void	handle_sigint(int sig)
{
	save_or_restore_settings(RESTORE);
	exit(sig);
}

static void	handle_sigwinch(int sig)
{
	(void)sig;
	/* resize window so re-draw some things.
	 First, calculate if it's possible to re-print the args, 
	 if not just print an error msg as "window too small" */
}

/*
**	Initialize the functions for handling signals.
**	If an error occurs, returns -1 or 0 otherwise.
*/

int			init_sig_handlers(void)
{
	if (signal(SIGINT, &(handle_sigint)) == SIG_ERR)
		return (-1);
	if (signal(SIGWINCH, &(handle_sigwinch)) == SIG_ERR)
		return (-1);
	return (0);
}