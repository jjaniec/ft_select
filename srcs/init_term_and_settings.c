/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term_and_settings.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 17:33:10 by cyfermie          #+#    #+#             */
/*   Updated: 2018/04/21 19:53:59 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
**	Initialize the Termcap library.
**	Returns -1 if an error occurs, 0 otherwise.
*/

int			init_term(void)
{
	char	*termtype;

	if (isatty(STDIN_FILENO) == 0)
	{
		ft_putstr_fd("ft_select: The standard output is not a valid terminal.\n", STDERR_FILENO);
		return (-1);
	}
	if ((termtype = getenv("TERM")) == NULL)
	{
		ft_putstr_fd("ft_select: Please set the env variable TERM\n", STDERR_FILENO);
		return (-1);
	}
	if (tgetent(NULL, termtype) < 1)
	{
		ft_putstr_fd("ft_select: Cannot initialize the terminal entry\n", STDERR_FILENO);
		return (-1);
	}
	return (0);
}

/*
**	The 'mode' parameter can be SAVE or RESTORE.
**	SAVE : the function saves the current terminal settings
**	RESTORE : the function restores the settings previously saved (see SAVE mode)
*/

void		save_or_restore_settings(int mode)
{
	static struct termios	orig_tios;

	if (mode == SAVE)
	{
		if (tcgetattr(STDIN_FILENO, &orig_tios) == -1)
			ft_exit(FATAL_ERROR, "Call to tcgetattr() failed\n");
	}
	else if (mode == RESTORE)
	{
		if (tcsetattr(STDIN_FILENO, TCSANOW, &orig_tios) == -1)
			ft_exit(FATAL_ERROR, "Failure while restoring the originals settings (tcsetattr() failed)\n");
		ft_putstr(END_SCR);
	}
}

/*
**	Save the originals settings with save_or_restore_settings() then change them.
**	Returns -1 if an error occurs, 0 otherwise.
*/

int			change_term_settings(struct s_term_caps	*tcaps)
{
	if (tcgetattr(STDIN_FILENO, &(tcaps->tios)) == -1)
		ft_exit(FATAL_ERROR, "Call to tcgetattr() failed\n");
	save_or_restore_settings(SAVE);
	tcaps->tios.c_lflag &= ~(ICANON);
	tcaps->tios.c_lflag &= ~(ECHO);
	if (tcsetattr(STDIN_FILENO, TCSANOW, &(tcaps->tios)) == -1)
	{
		save_or_restore_settings(RESTORE);
		ft_putstr_fd("Call to tcsetattr() failed\n", STDERR_FILENO);
		return (-1);
	}
	return (0);
}

/*
**	Initialize the main structure of the program
*/

void	init_tcaps(struct s_term_caps *tcaps, int argc, char **argv)
{
	tcaps->e_infos.elems = create_args_sorted_list(argv + 1);
	tcaps->e_infos.elems_count = argc - 1;
	tcaps->clear_s = tgetstr("cl", NULL);
	tcaps->movcur_s = tgetstr("cm", NULL);
	get_printing_width(&(tcaps->e_infos), argv + 1);
}
