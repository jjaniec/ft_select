/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 19:35:03 by jjaniec           #+#    #+#             */
/*   Updated: 2018/04/20 21:17:55 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
** Print elements list in rows based on term width and height
*/

static unsigned int		get_elems_per_row(t_term_caps *tcaps)
{
	return (tcaps->e_infos.elems_per_row = \
		tcaps->ts.ws_col / (tcaps->e_infos.width + 2));
}

void					print_args(t_term_caps *tcaps, char **args)
{
	int				i;
	unsigned int	j;

	i = -1;
	j = 0;
	if (tcaps->e_infos.width > 0)
		get_elems_per_row(tcaps);
	printf("elems/row: %d\n", tcaps->e_infos.elems_per_row);
	while (args[++i])
	{
		if (tcaps->e_infos.width > 0)
			printf("%-*s", (int)tcaps->e_infos.width + 2, args[i]);
		else
			printf("%-*s", (int)ft_strlen(args[i]) + 2, args[i]);
		j++;
		if (j == tcaps->e_infos.elems_per_row)
		{
			printf("\n");
			j = 0;
		}
	}
	printf("\n");
}
