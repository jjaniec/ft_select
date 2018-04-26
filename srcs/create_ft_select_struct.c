/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ft_select_struct.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 16:27:01 by jjaniec           #+#    #+#             */
/*   Updated: 2018/04/25 14:15:28 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
** Creates a t_ft_select struct, set it's $str ptr to $argptr and next to NULL
*/

t_ft_select_arg		*create_ft_select_arg_struct(t_term_caps *tcaps, \
						char *argptr, t_ft_select_arg *prev_elem_ptr)
{
	t_ft_select_arg		*e;
	char				*e_path;

	if (!(e = malloc(sizeof(t_ft_select_arg))))
		exit(EXIT_FAILURE);
	e->selected = false;
	e->str = argptr;
	e->prev = prev_elem_ptr;
	e_path = ((argptr[0] != '/') ? (ft_strjoin(tcaps->cwd, argptr)) : (argptr));
	e->stat_r = lstat(e_path, &(e->stats));
	printf("stats of e_path : %s - %d\n", e_path, e->stat_r);
	if (argptr[0] != '/')
		free(e_path);
	e->next = NULL;
	return (e);
}
