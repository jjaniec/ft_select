/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 19:03:00 by cyfermie          #+#    #+#             */
/*   Updated: 2018/04/19 21:33:40 by jjaniec          ###   ########.fr       */
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

# define FATAL_ERROR (2)
# define SAVE (1)
# define RESTORE (0)

/*
**	init_term_and_settings.c
*/
int		init_term(void);
int		manage_term_settings(void);
void	save_or_restore_settings(int mode);

/*
**	tools.c
*/
void	_clear_screen(void);

									#include <stdio.h> // debuuug

#endif