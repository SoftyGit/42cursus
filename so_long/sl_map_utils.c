/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:07:38 by yongjale          #+#    #+#             */
/*   Updated: 2023/02/20 21:28:24 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	sl_count_line(int fd)
{
	int	cnt;

	cnt = 0;
	while (get_next_line(fd))
		cnt++;
	if (!cnt)
		sl_error(NON_MAP_ERR);
	return (cnt);
}

char	**sl_record_map(int fd, int length)
{
	int		row;
	int		column;
	char	**map;

	row = 0;
	map = (char **)malloc(sizeof(char *) * (length + 1));
	while (row < length)
		map[row++] = get_next_line(fd);
	map[row] = NULL;
	return (map);
}

void	sl_assign_mapdata(char **map, t_vars *vars)
{
	int	row;
	int	col;

	row = 0;
	while (row < (vars->row_length))
	{
		if ((vars->col_length) != sl_strlen(map[row]))
			sl_error(NON_RECT_MAP_ERR);
		col = 0;
		while (col < (vars->col_length))
		{
			if (row == 0 || row == (vars->row_length) - 1
				|| col == 0 || col == (vars->col_length) - 1)
				if (map[row][col] != '1')
					sl_error(NON_RECT_MAP_ERR);
			if (map[row][col] == 'P')
				vars->l_start.amount++;
			else if (map[row][col] == 'E')
				vars->l_end.amount++;
			else if (map[row][col] == 'C')
				vars->l_prey.amount++;
			col++;
		}
		row++;
	}
}

void	sl_record_mapdata(char **map, int row, int col, t_vars *vars)
{
	t_locations	locations;
	
	if (row == 0 || row == (vars->row_length) - 1
		|| col == 0 || col == (vars->col_length) - 1)
		if (map[row][col] != '1')
			sl_error(NON_RECT_MAP_ERR);
	if (map[row][col] == 'P')
		locations = vars->l_start;
	else if (map[row][col] == 'E')
		locations = vars->l_end;
	else if (map[row][col] == 'C')
		locations = vars->l_prey;
	col++;
}

void	sl_check_mapdata(char **map, t_vars *vars)
{
	if (vars->l_start.amount != 1)
		sl_error(INVALID_PLAYER_ELEMENT_MAP_ERR);
	else if (vars->l_end.amount != 1)
		sl_error(INVALID_ESCAPE_ELEMENT_MAP_ERR);
	else if (vars->l_prey.amount == 0)
		sl_error(INVALID_PREY_ELEMENT_MAP_ERR);
}
