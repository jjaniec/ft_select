/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_term.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 17:33:10 by cyfermie          #+#    #+#             */
/*   Updated: 2018/04/21 21:43:33 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
** Initialize the Termcap library.
** Returns -1 if an error occurs, 0 otherwise.
*/

int			init_term(void)
{
	char	*termtype;

	if (isatty(STDIN_FILENO) == 0)
	{
		ft_putstr_fd(\
			"ft_select: The standard output is not a valid terminal.\n", \
			STDERR_FILENO);
		return (-1);
	}
	if ((termtype = getenv("TERM")) == NULL)
	{
		ft_putstr_fd(\
			"ft_select: Please set the env variable TERM\n", \
			STDERR_FILENO);
		return (-1);
	}
	if (tgetent(NULL, termtype) < 1)
	{
		ft_putstr_fd(\
			"ft_select: Cannot initialize the terminal entry\n", \
			STDERR_FILENO);
		return (-1);
	}
	return (0);
}

/*
** Save the originals settings with save_restore_term_settings() then change them.
** Returns -1 if an error occurs, 0 otherwise.
*/

int			change_term_settings(struct s_term_caps	*tcaps)
{
	if (tcgetattr(STDIN_FILENO, &(tcaps->tios)) == -1)
		ft_exit(FATAL_ERROR, "Call to tcgetattr() failed\n");
	save_restore_term_settings(SAVE);
	tcaps->tios.c_lflag &= ~(ICANON);
	tcaps->tios.c_lflag &= ~(ECHO);
	if (tcsetattr(STDIN_FILENO, TCSANOW, &(tcaps->tios)) == -1)
	{
		save_restore_term_settings(RESTORE);
		ft_putstr_fd("Call to tcsetattr() failed\n", STDERR_FILENO);
		return (-1);
	}
	return (0);
}
