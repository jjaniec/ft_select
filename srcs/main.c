/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:52:06 by cyfermie          #+#    #+#             */
/*   Updated: 2018/04/20 20:40:46 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	read_key(char key[SZBUFKEY])
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

void	ft_select(t_term_caps *tcaps, char **args)
{
	char	key[SZBUFKEY];

	ft_putstr(tcaps->clear_s);
	get_term_size(&(tcaps->ts));
	print_args(tcaps, args);
	while ("main loop for user interactions")
	{
		read_key(key);
		analyze_key(key);

		//for (int i = 0 ; key[i] ; ++i) printf("%d\n",key[i] );

		//printf("key = |%s|\n", key);
		//printf("%d", *key);
	}
}

int		main(int argc, char **argv)
{
	struct s_term_caps	tcaps;

	if (argc < 2)
	{
		ft_putstr_fd("usage: ft_select: argument1 [argument2 ...]\n",
		STDERR_FILENO);
		return (EXIT_FAILURE);
	}

	if (init_term() == -1 || change_term_settings(&tcaps) == -1 || init_sig_handlers() == -1)
		return (EXIT_FAILURE);

	init_tcaps(&tcaps, argc, argv);
	ft_select(&tcaps, argv + 1);
	save_or_restore_settings(RESTORE);
	return (EXIT_SUCCESS);
}
