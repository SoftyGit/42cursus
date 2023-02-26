/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:07:38 by yongjale          #+#    #+#             */
/*   Updated: 2023/02/25 23:31:41 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

	vars->prey_collect = 0;
	row = 0;
	while (row < (vars->row_length))
	{
		if ((vars->col_length) != (int)sl_strlen(map[row]))
			sl_error(NON_RECT_MAP_ERR);
		col = 0;
		while (col < (vars->col_length))
		{
			sl_record_mapdata(map, row, col, vars);
			col++;
		}
		row++;
	}
}

void	sl_record_mapdata(char **map, int row, int col, t_vars *vars)
{
	t_locations	*locations;
	int	num;
	int	cnt;
	
	num = 0;
	cnt = (vars->row_length * vars->col_length) % ENEMEY_DENSITY;
	if (row == 0 || row == (vars->row_length) - 1
		|| col == 0 || col == (vars->col_length) - 1)
		if (map[row][col] != '1')
			sl_error(NON_SURROUNG_WALL_MAP_ERR);
	if (map[row][col] == 'P')
		locations = &(vars->l_start);
	else if (map[row][col] == 'E')
		locations = &(vars->l_end);
	else if (map[row][col] == 'C')
	{
		locations = &(vars->l_prey);
		num = vars->l_prey.amount;
	}
	else
		return ;
	locations->amount++;
	locations->y[num] = row;
	locations->x[num] = col;
}

void	sl_check_mapdata(char **map, t_vars *vars)
{
	int	i;

	if (vars->l_start.amount != 1)
		sl_error(INVALID_PLAYER_ELEMENT_MAP_ERR);
	else if (vars->l_end.amount != 1)
		sl_error(INVALID_ESCAPE_ELEMENT_MAP_ERR);
	else if (vars->l_prey.amount == 0)
		sl_error(INVALID_PREY_ELEMENT_MAP_ERR);
	i = 0;
	while (i < vars->l_prey.amount)
	{
		sl_check_valid_path(i, map, vars);
		i++;
	}
	free(vars->map_recur);
}
