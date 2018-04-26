/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 12:54:44 by jjaniec           #+#    #+#             */
/*   Updated: 2018/04/25 14:01:07 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
** Print color associated to file type of e->str
*/

int		print_arg_color(t_term_caps *tcaps, t_ft_select_arg *e)
{
	if (S_ISDIR(e->stats.st_mode))
		return (printf("%s", tcaps->colors.di));
	if (S_ISLNK(e->stats.st_mode))
		return (printf("%s", tcaps->colors.ln));
	if (S_ISSOCK(e->stats.st_mode))
		return (printf("%s", tcaps->colors.so));
	if (S_ISFIFO(e->stats.st_mode))
		return (printf("%s", tcaps->colors.pi));
	if (S_ISBLK(e->stats.st_mode))
		return (printf("%s", tcaps->colors.bd));
	if (S_ISCHR(e->stats.st_mode))
		return (printf("%s", tcaps->colors.cd));
	if (e->stats.st_mode & S_IXUSR)
		return (printf("%s", tcaps->colors.ex));
	return (0);
}