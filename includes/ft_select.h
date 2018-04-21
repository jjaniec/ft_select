/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 19:03:00 by cyfermie          #+#    #+#             */
/*   Updated: 2018/04/21 18:41:22 by jjaniec          ###   ########.fr       */
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
# include <signal.h>

# define FATAL_ERROR (2)

# define SAVE (1)
# define RESTORE (0)

typedef struct				s_ft_select_arg
{
	char					*str;
	struct s_ft_select_arg	*next;
}							t_ft_select_arg;

typedef struct				s_elems_infos
{
	struct s_ft_select_arg	*elems;
	unsigned int			elems_count;
	int						width;
	unsigned int			elems_per_row;
}							t_elems_infos;

typedef struct				s_term_caps
{
	struct termios			tios;
	struct winsize			ts;
	struct s_elems_infos	e_infos;
	char					*clear_s;
}							t_term_caps;

/*
**	init_term_and_settings.c
*/

int		init_term(void);

int		change_term_settings(struct s_term_caps	*tcaps);

void	save_or_restore_settings(int mode);

/*
**	get_term_size.c
*/

void	get_term_size(struct winsize *ts);

/*
**	sig_management.c
*/

int		init_sig_handlers(void);

int		get_printing_width(t_elems_infos *e_infos, char **elems);

/*
** print_args.c
*/

void	print_args(t_term_caps *tcaps, t_ft_select_arg *li);

t_ft_select_arg			*create_args_sorted_list(char **args);

t_ft_select_arg		*create_ft_select_arg_struct(char *argptr);

void		free_args_list(t_ft_select_arg *li);


#endif