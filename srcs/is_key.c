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

bool	is_key_up_arrow(char *key)
{
	if (key[0] == 27 && key[1] == 91 && key[2] == 65 && key[3] == '\0')
		return (true);
	return (false);
}

bool	is_key_down_arrow(char *key)
{
	if (key[0] == 27 && key[1] == 91 && key[2] == 66 && key[3] == '\0')
		return (true);
	return (false);
}

bool	is_key_left_arrow(char *key)
{
	if (key[0] == 27 && key[1] == 91 && key[2] == 68 && key[3] == '\0')
		return (true);
	return (false);
}

bool	is_key_right_arrow(char *key)
{
	if (key[0] == 27 && key[1] == 91 && key[2] == 67 && key[3] == '\0')
		return (true);
	return (false);
}

bool	is_key_delete(char *key)
{
	if (key[0] == 27 && key[1] == 91 && key[2] == 51 && key[3] == 126
	&& key[4] == '\0')
		return (true);
	return (false);
}
