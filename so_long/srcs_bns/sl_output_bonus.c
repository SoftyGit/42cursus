/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_output_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:48:16 by yongjale          #+#    #+#             */
/*   Updated: 2023/09/24 21:17:15 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	sl_error(int code)
{
	write(1, "Error\n", 7);
	if (code == MALLOC_ERR || code == READ_ERR)
		write(1, "MALLOC/READ ERROR OCCURED", 26);
	else if (code == INPUT_ERR)
		write(1, "INPUT ELEMENTS ARE INVALID OR LACK/EXCESSIVE", 45);
	else if (code == NON_MAP_ERR)
		write(1, "MAP IS EMPTY", 13);
	else if (code == NON_RECT_MAP_ERR)
		write(1, "MAP IS NOT RECTANGULAR", 23);
	else if (code == NON_SURROUNG_WALL_MAP_ERR)
		write(1, "MAP IS NOT SURROUNDED BY WALLS", 31);
	else if (code == NON_VALID_PATH_FROM_PLAYER_TO_PREY)
		write(1, "THERE IS NO WAY TO APPROACH SOME END/PREYS POINTS", 50);
	else if (code == INVALID_WALL_MAP_ERR)
		write(1, "WALLS OF MAP ARE INVALID", 25);
	else if (code == INVALID_ELEMENTS_MAP_ERR)
		write(1, "INVALID START/END/PREYS POINTS OR VALUES", 41);
	else if (code == INVALID_PLAYER_ELEMENT_MAP_ERR)
		write(1, "INVALID_START_POINTS", 21);
	else if (code == INVALID_ESCAPE_ELEMENT_MAP_ERR)
		write(1, "INVALID_END_POINTS", 19);
	else if (code == INVALID_PREY_ELEMENT_MAP_ERR)
		write(1, "INVALID_PREYS_POINTS", 21);
	exit(code);
}
