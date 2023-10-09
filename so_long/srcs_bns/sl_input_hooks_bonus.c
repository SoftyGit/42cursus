/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_input_hooks_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:59:15 by yongjale          #+#    #+#             */
/*   Updated: 2023/09/28 14:06:16 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	sl_key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		exit(0);
	else
		sl_control_hook(keycode, vars);
	return (0);
}

int	sl_destroy_hook(t_vars *vars)
{
	vars->prey_collect = -1;
	exit(0);
}

void	sl_control_hook(int keycode, t_vars *vars)
{
	int	row_var;
	int	col_var;

	row_var = 0;
	col_var = 0;
	if (keycode == KEY_W)
		row_var--;
	else if (keycode == KEY_S)
		row_var++;
	else if (keycode == KEY_D)
		col_var++;
	else if (keycode == KEY_A)
		col_var--;
	else
		return ;
	sl_move_player(row_var, col_var, vars);
}

void	sl_move_player(int row_var, int col_var, t_vars *vars)
{
	char	**map;
	char	*movements;
	int		*row;
	int		*col;

	row = &vars->l_start.y[0];
	col = &vars->l_start.x[0];
	map = vars->map_addr;
	if (*row + row_var >= 0 && *row + row_var < vars->row_length
		&& *col + col_var >= 0 && *col + col_var < vars->col_length
		&& map[*row + row_var][*col + col_var] != '1')
	{
		*row += row_var;
		*col += col_var;
		if (map[*row][*col] == 'M')
			exit(0);
		movements = sl_itoa(++vars->move_records);
		sl_check_elements_when_move(*row, *col, map, vars);
		sl_up_window(row_var, col_var, map, vars);
		mlx_string_put(vars->mlx, vars->win, 24, 36, 0x000000, movements);
		free(movements);
	}
}
