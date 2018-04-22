/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 19:25:02 by cyfermie          #+#    #+#             */
/*   Updated: 2018/04/21 21:43:06 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

extern t_term_caps 		*g_tcaps;
extern t_ft_select_arg 	*g_li;

static void		handle_sigint(int sig)
{
	save_restore_term_settings(RESTORE);
	exit(sig);
}

static void	handle_sigwinch(int sig)
{
	(void)sig;





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
