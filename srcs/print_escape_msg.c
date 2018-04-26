/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_escape_msg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 20:42:09 by jjaniec           #+#    #+#             */
/*   Updated: 2018/04/26 20:47:56 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

extern t_term_caps		*g_tcaps;

/*
**	Print a message to say how to quit the program.
*/

void			print_escape_msg(void)
{
	ft_putstr_fd(tgoto(g_tcaps->movcur_s, g_tcaps->ts.ws_col - 21, \
	g_tcaps->ts.ws_row), STDIN_FILENO);
	ft_putstr_fd(COLOR_BACK_WHITE, STDIN_FILENO);
	ft_putstr_fd(COLOR_CAR_BLUE, STDIN_FILENO);
	ft_putstr_fd(" PRESS ESCAPE TO QUIT", STDIN_FILENO);
	ft_putstr_fd(END_COLOR, STDIN_FILENO);
}
