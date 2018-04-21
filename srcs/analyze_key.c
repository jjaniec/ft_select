/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 16:14:42 by cyfermie          #+#    #+#             */
/*   Updated: 2018/04/21 21:46:03 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
**	Launch the function linked to the parameter 'key'.
**	If no function is linked to the key, it does nothing.
**	Keys recognized : up/down/left/right arrows -
**	escape - space - backspace - delete - return.
*/

static void	analyze_key_arrow(char key[SZBUFKEY])
{
	if (is_key_up_arrow(key) == true)
	{

	}
	else if (is_key_down_arrow(key) == true)
	{
		
	}
	else if (is_key_left_arrow(key) == true)
	{
		
	}
	else if (is_key_right_arrow(key) == true)
	{
		
	}
}

void		analyze_key(char key[SZBUFKEY])
{
	if (key[0] == KEY_ESCAPE && key[1] == '\0')
	{
		handle_escape();
	}
	else if (key[0] == KEY_SPACE && key[1] == '\0')
	{

	}
	else if ((key[0] == KEY_BS && key[1] == '\0') || is_key_delete(key))
	{

	}
	else if (key[0] == KEY_RETURN && key[1] == '\0')
	{

	}
	else
		analyze_key_arrow(key);
}
