/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 19:35:03 by jjaniec           #+#    #+#             */
/*   Updated: 2018/04/21 22:15:11 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
** Calculate number of elements to print per row
*/

static unsigned int		get_elems_per_row(t_term_caps *tcaps)
{
	return (tcaps->e_infos.elems_per_row = \
		tcaps->ts.ws_col / (tcaps->e_infos.width + 2));
}

/*
** Print element based on tcaps->e_infos.width with FORMAT_RESET if specified
*/

static void				print_arg_fmt_str(t_term_caps *tcaps, \
							char *s, int fmt_len)
{
	printf("%-*s", \
		((tcaps->e_infos.width > 0) ? \
			((int)tcaps->e_infos.width) : ((int)ft_strlen(s))) + \
		2 + fmt_len, s);
}

/*
** Join and print element with FORMAT_RESET if needed
** and pass it to print_arg_fmt_str, then free allocated ptr
*/

static void				print_arg_fmt(t_term_caps *tcaps, t_ft_select_arg *e)
{
	char	*str_fmt;

	str_fmt = e->str;
	if (e->is_selected == true)
	{
		printf(ELEM_SELECTED);
		str_fmt = ft_strjoin(e->str, FORMAT_RESET);
		print_arg_fmt_str(tcaps, str_fmt, ft_strlen(FORMAT_RESET));
	}
	else
		print_arg_fmt_str(tcaps, str_fmt, 0);
	if (str_fmt != e->str)
		free(str_fmt);
}

/*
** Calls print_arg_fmt on every element in the linked list,
** prints a newline when necessary
*/

void					print_args(t_term_caps *tcaps, t_ft_select_arg *li)
{
	unsigned int	j;
	t_ft_select_arg	*ptr;

	j = 0;
	if (tcaps->e_infos.width > 0)
		get_elems_per_row(tcaps);
	printf("elems/row: %d\n", tcaps->e_infos.elems_per_row);
	ptr = li;
	while (ptr)
	{
		print_arg_fmt(tcaps, ptr);
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
