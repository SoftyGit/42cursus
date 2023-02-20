/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:48:16 by yongjale          #+#    #+#             */
/*   Updated: 2023/02/20 21:23:24 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_error(int code)
{
	if (code == MALLOC_ERR)
		write(1, "MALLOC ERROR OCCURED", 21);
	else if (code == READ_ERR)
		write(1, "WRITE ERROR OCCURED", 20);
	else if (code == INPUT_ERR)
		write(1, "INPUT ELEMENTS ARE INVALID OR LACK/EXCESSIVE", 45);
	else if (code == NON_MAP_ERR)
		write(1, "MAP IS EMPTY", 13);
	else if (code == NON_RECT_MAP_ERR)
		write(1, "MAP IS NOT RECTANGULAR", 23);
	else if (code == INVALID_WALL_MAP_ERR)
		write(1, "WALLS OF MAP ARE INVALID", 25);
	else if (code == INVALID_ELEMENTS_MAP_ERR)
		write(1, "INVALID START/END/PREYS POINTS", 31);
	else if (code == INVALID_PLAYER_ELEMENT_MAP_ERR)
		write(1, "INVALID_START_POINTS", 21);
	else if (code == INVALID_ESCAPE_ELEMENT_MAP_ERR)
		write(1, "INVALID_END_POINTS", 19);
	else if (code == INVALID_PREY_ELEMENT_MAP_ERR)
		write(1, "INVALID_PREYS_POINTS", 21);
	exit(code);
}
