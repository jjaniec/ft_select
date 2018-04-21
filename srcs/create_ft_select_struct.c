/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ft_select_struct.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 16:27:01 by jjaniec           #+#    #+#             */
/*   Updated: 2018/04/21 16:31:01 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
** Creates a t_ft_select struct, set it's $str ptr to $argptr and next to NULL
*/

t_ft_select_arg		*create_ft_select_arg_struct(char *argptr)
{
	t_ft_select_arg		*e;

	if (!(e = malloc(sizeof(t_ft_select_arg))))
		exit(EXIT_FAILURE);
	e->str = argptr;
	e->next = NULL;
	return (e);
}