/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 18:40:15 by jjaniec           #+#    #+#             */
/*   Updated: 2018/04/27 16:43:04 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
** Checks if first argument is equal to "--ascii-sort" or "--", no need of a
** complex parser if we only have one option,
** if ascii sort is specified, toggle tcaps->opt.ascii_sort to true,
** else set it to false,
** then return the number of options found, "--" also counts as one
*/

int		parse_options(t_term_caps *tcaps, char **argv)
{
	if (argv && argv[0] && argv[0][0] == '-' && argv[0][1])
	{
		if (ft_strcmp(argv[0], "--ascii-sort") == 0)
		{
			tcaps->opt.ascii_sort = true;
			if (argv[1] && ft_strcmp(argv[1], "--") == 0)
				return (2);
			return (1);
		}
		else if (ft_strcmp(argv[0], "--") == 0)
			return (1);
		else
		{
			ft_putstr_fd("ft_select: no such option: ", 2);
			ft_putstr_fd(argv[0] + 1, 2);
			ft_putstr_fd("\n", 2);
			exit(EXIT_FAILURE);
		}
	}
	tcaps->opt.ascii_sort = false;
	return (0);
}
