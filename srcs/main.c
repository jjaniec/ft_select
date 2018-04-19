/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:52:06 by cyfermie          #+#    #+#             */
/*   Updated: 2018/04/19 21:35:12 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	read_key(char key[5])
{
	ssize_t	read_ret;

	while ("waiting for a pressed key")
	{
		ft_memset(key, 0, 5);
		read_ret = read(STDIN_FILENO, key, 4);
		if (read_ret == -1)
			ft_exit(FATAL_ERROR, "Call to read() failed\n");
		if (read_ret > 0)
			break ;
	}
}

void	ft_select(char **args)
{
	char	key[5];

	while ("ceci est une boucle")
	{
		read_key(key);

		printf("key = |%s|\n", key);


	}
}

int		main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putstr_fd("usage: ft_select: argument1 [argument2 ...]\n",
		STDERR_FILENO);
		return (EXIT_FAILURE);
	}

	if (init_term() == -1 || manage_term_settings() == -1)
		return (EXIT_FAILURE);

	_clear_screen();
	ft_select(argv + 1);

	save_or_restore_settings(RESTORE);
	return (EXIT_SUCCESS);
}