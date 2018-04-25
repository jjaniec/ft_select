/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:52:06 by cyfermie          #+#    #+#             */
/*   Updated: 2018/04/25 12:04:56 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

t_term_caps 		*g_tcaps;

t_ft_select_arg 	*g_li;

/*
** Read user input and store it in key
*/

static void		read_key(char key[SZBUFKEY])
{
	ssize_t	read_ret;

	while ("waiting for a pressed key")
	{
		ft_memset(key, '\0', SZBUFKEY);
		read_ret = read(STDIN_FILENO, key, SZBUFKEY - 1);
		if (read_ret == -1)
			ft_exit(FATAL_ERROR, "Call to read() failed\n");
		if (read_ret > 0)
			break ;
	}
}

/*
** Print cli arguments and anylyse input in a loop
*/

static void		ft_select(t_term_caps *tcaps)
{
	char	key[SZBUFKEY];

	ft_putstr(INIT_SCR);
	get_term_size(&(tcaps->ts));
	print_args(tcaps, tcaps->e_infos.elems);
	while ("main loop for user interactions")
	{
		read_key(key);
		analyze_key(tcaps, key);
	}
}

static void		init_colors(t_term_caps *tcaps)
{
	tcaps->colors.di = DIR_COLOR;
	tcaps->colors.ln = SYMLINK_COLOR;
	tcaps->colors.so = SOCKET_COLOR;
	tcaps->colors.pi = PIPE_COLOR;
	tcaps->colors.ex = EXEC_COLOR;
	tcaps->colors.bd = BLOCK_SPE_COLOR;
	tcaps->colors.cd = CHAR_SPE_COLOR;
}

/*
**	Initialize the main structure of the program
*/

static void		init_tcaps(t_term_caps *tcaps, int argc, char **argv)
{
	char	cwd[1024];

	tcaps->e_infos.elems = \
		create_args_list(tcaps, argv + 1 + parse_options(tcaps, argv + 1));
	tcaps->e_infos.elems_first = tcaps->e_infos.elems;
	tcaps->e_infos.elems_count = argc - 1;
	tcaps->clear_s = tgetstr("cl", NULL);
	tcaps->movcur_s = tgetstr("cm", NULL);
	get_printing_width(&(tcaps->e_infos), argv + 1);
	tcaps->cursor_pos_ptr = tcaps->e_infos.elems_first;
	if ((tcaps->cwd = getcwd(cwd, sizeof(cwd))) != NULL)
		init_colors(tcaps);
}

int				main(int argc, char **argv)
{
	struct s_term_caps	tcaps;

	g_tcaps = &tcaps;
	g_li = tcaps.e_infos.elems;
	if (argc < 2)
	{
		ft_putstr_fd("usage: ft_select: argument1 [argument2 ...]\n",
		STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (init_term() == -1 || change_term_settings(&tcaps) == -1 || \
		init_sig_handlers() == -1)
		return (EXIT_FAILURE);
	init_tcaps(&tcaps, argc, argv);
	ft_select(&tcaps);
	free_args_list(tcaps.e_infos.elems);
	save_restore_term_settings(RESTORE);
	return (EXIT_SUCCESS);
}
