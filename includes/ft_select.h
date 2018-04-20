/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 19:03:00 by cyfermie          #+#    #+#             */
/*   Updated: 2018/04/20 17:16:17 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <libft.h>
# include <stdlib.h>
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <errno.h>
# include <stdio.h>
# include <sys/ioctl.h>
#include <signal.h>


# define FATAL_ERROR (2)
# define SAVE (1)
# define RESTORE (0)

typedef struct			s_term_caps
{
	struct termios		tios;
	struct winsize		ts;
	char				*clear_s;
}						t_term_caps;

/*
**	init_term_and_settings.c
*/

int		init_term(void);

int		change_term_settings(struct s_term_caps	*tcaps);

void	save_or_restore_settings(int mode);

/*
**	tools.c
*/

void	_clear_screen(char *cl);

void	get_term_size(struct winsize *ts);

/*
**	sig_management.c
*/

int		init_sig_handlers(void);

#endif