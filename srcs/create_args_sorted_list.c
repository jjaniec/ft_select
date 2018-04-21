/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_args_sorted_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 16:36:37 by jjaniec           #+#    #+#             */
/*   Updated: 2018/04/21 16:50:33 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
** Creates a linked list of cli arguments, sorted by ascii values w/ ft_strcmp
*/

static t_ft_select_arg	*append_arg(t_ft_select_arg *li, t_ft_select_arg *new)
{
	t_ft_select_arg	*ptr;
	t_ft_select_arg	*prev;

	ptr = li;
	prev = NULL;
	if (li && new)
	{
		while (ptr && ptr->next && ft_strcmp(ptr->str, new->str) > 0)
		{
			prev = ptr;
			ptr = ptr->next;
		}
		if (!prev)
		{
			new->next = li;
			return (new);
		}
		else
			ptr->next = new;
	}
	return (li);
}

t_ft_select_arg			*create_args_sorted_list(char **args)
{
	t_ft_select_arg		*r;
	t_ft_select_arg		*li;
	int					i;

	li = NULL;
	r = li;
	i = -1;
	while (args[++i])
	{
		if (li)
		{
			li = create_ft_select_arg_struct(args[i]);
			r = li;
		}
		else
			li = append_arg(li, create_ft_select_arg_struct(args[i]));
	}
	return (r);
}
