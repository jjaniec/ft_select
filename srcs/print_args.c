/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 19:35:03 by jjaniec           #+#    #+#             */
/*   Updated: 2018/04/20 20:41:05 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
** Print elements list in rows based on term width and height
*/

static unsigned int		get_elems_per_row(t_term_caps *tcaps)
{
	return (tcaps->e_infos.elems_per_row = \
		tcaps->ts.ws_col / tcaps->e_infos.width);
}

void					print_args(t_term_caps *tcaps, char **args)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	get_elems_per_row(tcaps);
	printf("elems/row: %d\n", tcaps->e_infos.elems_per_row);
	while (args[++i])
	{
		printf("%-*s", tcaps->e_infos.width, args[i]);
		j++;
		if (j == tcaps->e_infos.elems_per_row)
		{
			printf("\n");
			j = 0;
		}
	}
}
