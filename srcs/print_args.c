/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 19:35:03 by jjaniec           #+#    #+#             */
/*   Updated: 2018/04/21 21:03:51 by jjaniec          ###   ########.fr       */
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

void					print_args(t_term_caps *tcaps, t_ft_select_arg *li)
{
	unsigned int	j;
	t_ft_select_arg	*ptr;
	char			*str_fmt;

	j = 0;
	if (tcaps->e_infos.width > 0)
		get_elems_per_row(tcaps);
	printf("elems/row: %d\n", tcaps->e_infos.elems_per_row);
	ptr = li;
	while (ptr)
	{
		str_fmt = ptr->str;
		if (ptr->is_selected == true)
		{
			printf(ELEM_SELECTED);
			str_fmt = ft_strjoin(ptr->str, FORMAT_RESET);
		}
		if (tcaps->e_infos.width > 0)
			printf("%-*s", (int)tcaps->e_infos.width + 2 + \
				(int)ft_strlen(FORMAT_RESET), str_fmt);
		else
			printf("%-*s", (int)ft_strlen(ptr->str) + 2 + \
				(int)ft_strlen(FORMAT_RESET), str_fmt);
		if (ptr->is_selected == true)
			free(str_fmt);
		j++;
		if (j == tcaps->e_infos.elems_per_row)
		{
			printf("\n");
			j = 0;
		}
		ptr = ptr->next;
	}
	printf("\n");
}
