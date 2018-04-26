/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ft_select_struct.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 16:27:01 by jjaniec           #+#    #+#             */
/*   Updated: 2018/04/26 20:40:18 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static char			*ft_strjoin_path(char *s1, char *s2)
{
	char	*r;
	size_t	l;

	l = ft_strlen(s1);
	if (l > 0 && s1[l - 1] == '/')
		l -= 1;
	r = malloc((l + ft_strlen(s2) + 2) * sizeof(char));
	ft_strcpy(r, s1);
	ft_strcpy(r + l + 1, s2);
	r[l] = '/';
	return (r);
}

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
	e_path = ((argptr[0] != '/') ? \
		(ft_strjoin_path(tcaps->cwd, argptr)) : (argptr));
	e->stat_r = lstat(e_path, &(e->stats));
	if (argptr[0] != '/')
		free(e_path);
	e->next = NULL;
	return (e);
}
