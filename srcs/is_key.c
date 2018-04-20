/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 21:25:23 by cyfermie          #+#    #+#             */
/*   Updated: 2018/04/20 21:25:25 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

bool	is_key_escape(char *key)
{
	if (*key == 27)
		return (true);
	return (false);
}

bool	is_key_up_arrow(char *key)
{
	if (key[0] == 27 && key[1] == 91 && key[2] == 65)
		return (true);
	return (false);
}

bool	is_key_down_arrow(char *key) // 3
{
	if (key[0] == 27 && key[1] == 91 && key[2] == 65)
		return (true);
	return (false);
}

bool	is_key_left_arrow(char *key) // 3
{
	if (key[0] == 27 && key[1] == 91 && key[2] == 65)
		return (true);
	return (false);
}

bool	is_key_right_arrow(char *key) // 3
{
	if (key[0] == 27 && key[1] == 91 && key[2] == 65)
		return (true);
	return (false);
}