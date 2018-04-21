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
#include <stdbool.h>

# define FATAL_ERROR (2)

# define SZBUFKEY (5)

enum e_one_byte_keycodes
{
	KEY_RETURN = 10,
	KEY_ESCAPE = 27,
	KEY_SPACE = 32,
	KEY_BS = 127
};

enum e_save_or_restore_settings_modes
{
	SAVE,
	RESTORE
};

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
	char					*movcur_s;
}							t_term_caps;

/*
**	init_term_and_settings.c
*/

int		init_term(void);

int		change_term_settings(struct s_term_caps	*tcaps);

void	save_or_restore_settings(int mode);

void	init_tcaps(struct s_term_caps *tcaps, int argc, char **argv);


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


/*
**	is_key.c
*/

bool	is_key_up_arrow(char *key);

bool	is_key_down_arrow(char *key);

bool	is_key_left_arrow(char *key);

bool	is_key_right_arrow(char *key);

bool	is_key_delete(char *key);


/*
**	analyze_key.c
*/

void	analyze_key(char key[SZBUFKEY]);

#endif
