/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 19:03:00 by cyfermie          #+#    #+#             */
/*   Updated: 2018/04/25 16:09:51 by jjaniec          ###   ########.fr       */
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
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>

# define FORMAT_RESET "\e[0m"
# define ELEM_SELECTED_FMT "\e[7m"
# define CURSOR_POS_FMT "\e[4m"

# define FATAL_ERROR (2)

# define SZBUFKEY (5)

# define INIT_SCR	"\e[?1049h"
# define END_SCR	"\e[?1049l"

# define DIR_COLOR "\e[1;36m"
# define SYMLINK_COLOR "\e[35m"
# define SOCKET_COLOR "\e[32m"
# define PIPE_COLOR "\e[33m"
# define EXEC_COLOR "\e[31m"
# define BLOCK_SPE_COLOR "\e[34;46m"
# define CHAR_SPE_COLOR "\e[34;43m"

# define COLOR_RESET "\e[0m"


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
	RESTORE,
	RESTORE_NO_SCR_END
};

typedef struct				s_ft_select_cols
{
	char					*di;
	char					*ln;
	char					*so;
	char					*pi;
	char					*ex;
	char					*bd;
	char					*cd;
}							t_ft_select_cols;

/*
** str: pointer to argument in argv
** selected: false or true to know if element has been selected w/ space
** stats: stats of (pwd + str)
** stat_r: return code of lstat()
** index: index of element in the linked list (given by print_args())
** prev: previous element in the linked list
** next: next element in the linked list
*/

typedef struct				s_ft_select_arg
{
	char					*str;
	bool					selected;
	struct stat				stats;
	int						stat_r;
	unsigned int			index;
	struct s_ft_select_arg	*prev;
	struct s_ft_select_arg	*next;
}							t_ft_select_arg;

/*
** elems: linked list of all cli arguments
** elems_first: pointer to first element of the linked list
** elems_last: pointer to last element of the linked list
** elems_count: count of elements in the linked list
** width: length of the longest cli argument
** elems_per_row: number of elems to print per row
*/

typedef struct				s_elems_infos
{
	struct s_ft_select_arg	*elems;
	struct s_ft_select_arg	*elems_first;
	struct s_ft_select_arg	*elems_last;
	unsigned int			elems_count;
	int						width;
	unsigned int			elems_per_row;
}							t_elems_infos;

/*
** ascii_sort: boolean to know if ascii sorting is activated or not
*/

typedef struct				s_ft_select_opts
{
	bool					ascii_sort;
}							t_ft_select_opts;

/*
** tios: struct to save term settings
** ts: struct to store term width and height
** e_infos: see struct s_elems_infos
** opt: see struct s_ft_select_opts
** colors: see struct s_ft_select_cols
** clear_s: string to print to do a terminal clear
** cursor_pos_ptr: pointer to current cli argument in the linked list
** movcur_s: string to print to move terminal cursor
** cwd: current working directory,
**      if getcwd returns an error it will be set to NULL
*/

typedef struct				s_term_caps
{
	struct termios			tios;
	struct winsize			ts;
	struct s_elems_infos	e_infos;
	struct s_ft_select_opts	opt;
	struct s_ft_select_cols	colors;
	char					*clear_s;
	t_ft_select_arg			*cursor_pos_ptr;
	char					*movcur_s;
	char					*cwd;

}							t_term_caps;

/*
** analyze_key.c
*/

void						analyze_key(t_term_caps *tcaps, char key[SZBUFKEY]);

/*
** create_args_list.c
*/

t_ft_select_arg				*create_args_list(t_term_caps *tcaps, \
								char **args);

/*
** create_args_sorted_list.c
*/

t_ft_select_arg				*create_args_sorted_list(t_term_caps *tcaps, \
								char **args);

/*
** create_ft_select_struct.c
*/

t_ft_select_arg				*create_ft_select_arg_struct(t_term_caps *tcaps, \
								char *argptr, t_ft_select_arg *prev_elem_ptr);

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

void						refresh_display(t_term_caps *tcaps);

void						handle_key_return(t_term_caps *tcaps);

void						handle_key_bs(t_term_caps *tcaps);

void						handle_escape(t_term_caps *tcaps);

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

t_ft_select_arg				*move_cursor_index(t_term_caps *tcaps, \
								int move_pos, t_ft_select_arg *args_ptr, int stop_at_null);

/*
** parse_options.c
*/

int							parse_options(t_term_caps *tcaps, char **argv);

/*
** print_arg_color.c
*/

int							print_arg_color(t_term_caps *tcaps, \
								t_ft_select_arg *e);

#endif
