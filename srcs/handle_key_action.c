/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_action.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 21:11:14 by jjaniec           #+#    #+#             */
/*   Updated: 2018/04/21 21:42:56 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
** Handle escape key
*/

void	handle_escape(void)
{
	save_restore_term_settings(RESTORE);
	exit(EXIT_SUCCESS);
}
