/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_path_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:14:38 by yongjale          #+#    #+#             */
/*   Updated: 2023/03/05 14:43:46 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_check_valid_path(int num, char **map, t_vars *vars)
{
	int	row;
	int	col;
	int	i;

	row = vars->row_length;
	col = vars->col_length;
	if (vars->map_recur == NULL)
	{
		vars->map_recur = (char *)malloc(row * col + 1);
		if (!vars->map_recur)
			sl_error(MALLOC_ERR);
	}
	i = 0;
	while (i < row * col)
		vars->map_recur[i++] = 0;
	vars->map_recur[i] = 0;
	if (sl_recur_prey(vars->l_prey.y[num], vars->l_prey.x[num], map, vars) == 0)
	{
		free(vars->map_recur);
		sl_error(NON_VALID_PATH_FROM_PLAYER_TO_PREY);
	}
}

int	sl_recur_prey(int row, int col, char **map, t_vars *vars)
{
	int	status;

	status = 0;
	if (map[row][col] == 'P')
		return (1);
	if (sl_check_valid_recur(row - 1, col, vars, status))
		status = sl_recur_prey(row - 1, col, map, vars);
	if (sl_check_valid_recur(row, col - 1, vars, status))
		status = sl_recur_prey(row, col - 1, map, vars);
	if (sl_check_valid_recur(row + 1, col, vars, status))
		status = sl_recur_prey(row + 1, col, map, vars);
	if (sl_check_valid_recur(row, col + 1, vars, status))
		status = sl_recur_prey(row, col + 1, map, vars);
	return (status);
}

int	sl_check_valid_recur(int row, int col, t_vars *vars, int status)
{
	if (status == 1)
		return (0);
	if (row >= 0 && row < vars->row_length
		&& col >= 0 && col < vars->col_length
		&& vars->map_addr[row][col] != '1'
		&& vars->map_recur[row * (vars->col_length) + col] == 0)
	{
		vars->map_recur[row * (vars->col_length) + col] = 1;
		return (1);
	}
	return (0);
}
