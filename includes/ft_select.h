/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 19:03:00 by cyfermie          #+#    #+#             */
/*   Updated: 2018/04/22 20:34:54 by jjaniec          ###   ########.fr       */
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
# include <stdbool.h>

# define FORMAT_RESET "\e[0m"
# define ELEM_SELECTED_FMT "\e[7m"
# define CURSOR_POS_FMT "\e[4m"

# define FATAL_ERROR (2)

# define SZBUFKEY (5)

# define INIT_SCR	"\e[?1049h"
# define END_SCR	"\e[?1049l"

enum						e_one_byte_keycodes
{
	KEY_RETURN = 10,
	KEY_ESCAPE = 27,
	KEY_SPACE = 32,
	KEY_BS = 127
};

enum						e_save_restore_term_settings_modes
{
	SAVE,
	RESTORE
};

typedef struct				s_ft_select_arg
{
	char					*str;
	bool					selected;
	struct s_ft_select_arg	*prev;
	struct s_ft_select_arg	*next;
}							t_ft_select_arg;

typedef struct				s_elems_infos
{
	struct s_ft_select_arg	*elems;
	struct s_ft_select_arg	*elems_first;
	struct s_ft_select_arg	*elems_last;
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
	t_ft_select_arg			*cursor_pos_ptr;
	char					*movcur_s;

}							t_term_caps;

/*
** analyze_key.c
*/

void						analyze_key(char key[SZBUFKEY]);

/*
** create_args_sorted_list.c
*/

t_ft_select_arg				*create_args_sorted_list(t_term_caps *tcaps, \
								char **args);

/*
** create_ft_select_struct.c
*/

t_ft_select_arg				*create_ft_select_arg_struct(char *argptr, \
								t_ft_select_arg *prev_elem_ptr);

/*
** free_args_list.c
*/

void						free_args_list(t_ft_select_arg *li);

/*
** get_printing_width.c
*/

int							get_printing_width(t_elems_infos *e_infos, \
								char **elems);

/*
**	get_term_size.c
*/

void						get_term_size(struct winsize *ts);

/*
** handle_key_action.c
*/

void						handle_escape(void);

/*
**	is_key.c
*/

bool						is_key_up_arrow(char *key);

bool						is_key_down_arrow(char *key);

bool						is_key_left_arrow(char *key);

bool						is_key_right_arrow(char *key);

bool						is_key_delete(char *key);

/*
** print_args.c
*/

void						print_args(t_term_caps *tcaps, t_ft_select_arg *li);

/*
** save_restore_term_settings.c
*/

void						save_restore_term_settings(int mode);

/*
** sig_management.c
*/

int							init_sig_handlers(void);

/*
** update_term.c
*/

int							init_term(void);

int							change_term_settings(struct s_term_caps	*tcaps);

/*
** cursor_movement.c
*/

t_ft_select_arg				*move_cursor_index(int move_pos, \
								t_ft_select_arg *args_ptr);

#endif
