/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_term_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:59:08 by jjaniec           #+#    #+#             */
/*   Updated: 2018/04/20 17:01:21 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
** Get terminal rows and column count using ioctl
** ts: winsize struct to store rows and cols count
** return -1 and print and error message if ioctl failed,
** otherwise return 0
*/

int			get_term_size(struct winsize *ts)
{
	if (-1 == ioctl(STDOUT_FILENO, TIOCGWINSZ, ts))
	{
		ft_putstr_fd("ft_select: Failed to get terminal size\n", STDERR_FILENO);
		ts->ws_row = -1;
		ts->ws_col = -1;
		return (-1);
	}
	printf("lines %d\n", ts->ws_row);
	printf("columns %d\n", ts->ws_col);
	return (0);
}
