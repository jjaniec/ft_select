/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_args_sorted_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 16:36:37 by jjaniec           #+#    #+#             */
/*   Updated: 2018/04/21 18:31:11 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
** Creates a linked list of cli arguments, sorted by ascii values w/ ft_strcmp
*/

/*
** Skip elements with inferior ascii values
*/

static void				skip_args(t_ft_select_arg **ptr, \
							t_ft_select_arg **prev, t_ft_select_arg *new)
{
	if (ptr && *ptr && new)
	{
		while (ptr && *ptr && ft_strcmp((*ptr)->str, new->str) < 0)
		{
			(*prev) = (*ptr);
			(*ptr) = (*ptr)->next;
		}
	}
}

/*
** Use skip_args to append element to the linked list,
** if previous is equal to NULL after skip_args has been called, the beginning of
** the linked list is changed as the value of new and new->next will be equal to li
*/

static t_ft_select_arg	*append_arg(t_ft_select_arg *li, t_ft_select_arg *new)
{
	t_ft_select_arg	*ptr;
	t_ft_select_arg	*prev;

	ptr = li;
	prev = NULL;
	if (li && new)
	{
		skip_args(&ptr, &prev, new);
		if (!prev)
		{
			new->next = li;
			return (new);
		}
		prev->next = new;
		new->next = ptr;
		return (li);
	}
	return (li);
}

/*
** If li is not yet initialized, assign it as a new element, otherwise
** re-assign it as the return value of append_arg to allow args with
** inferior ascii values than the first element to be found
*/

t_ft_select_arg			*create_args_sorted_list(char **args)
{
	t_ft_select_arg		*r;
	t_ft_select_arg		*li;
	int					i;

	li = NULL;
	r = li;
	i = 0;
	while (args[i])
	{
		if (!li)
		{
			li = create_ft_select_arg_struct(args[i]);
			r = li;
		}
		else
			li = append_arg(li, create_ft_select_arg_struct(args[i]));
		i++;
	}
	return (li);
}
