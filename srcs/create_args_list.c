/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_args_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:11:31 by jjaniec           #+#    #+#             */
/*   Updated: 2018/04/24 20:31:22 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <ft_select.h>

/*
** Create linked list and append each element to the end, then return
** the beginning of the linked list
*/

t_ft_select_arg	*create_args_list(t_term_caps *tcaps, char **args)
{
	t_ft_select_arg	*r;
	t_ft_select_arg	*li;
	int				i;

	r = NULL;
	i = 0;
	if (tcaps->opt.ascii_sort == true)
		return (create_args_sorted_list(tcaps, args));
	while (args[i])
	{
		if (!r)
		{
			li = create_ft_select_arg_struct(args[i], NULL);
			tcaps->e_infos.elems_last = li;
			r = li;
		}
		else
		{
			li->next = create_ft_select_arg_struct(args[i], li);
			li = li->next;
		}
		i++;
	}
	tcaps->e_infos.elems_last = li;
	return (r);
}