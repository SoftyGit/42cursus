/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_input_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:59:15 by yongjale          #+#    #+#             */
/*   Updated: 2023/02/21 17:10:36 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	int	row;

	row = 0;
	while (row < vars->row_length)
		free(vars->map_addr[row]);
	free(vars->map_addr);
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
	sl_move_player(row_var, col_var, vars);
}

void	sl_move_player(int row_var, int col_var, t_vars *vars)
{
	char	**map;
	char	*movements;
	map = vars->map_addr;
	if (vars->l_start.y[0] + row_var >= 0 && vars->l_start.y[0] + row_var < vars->row_length)
		if (vars->l_start.x[0] + col_var >= 0 && vars->l_start.x[0] + col_var < vars->col_length)
			if (map[vars->l_start.y[0] + row_var][vars->l_start.x[0] + col_var] != '1')
			{
				vars->l_start.y[0] += row_var;
				vars->l_start.x[0] += col_var;
				movements = sl_itoa(++vars->move_records);
				write(1, "MOVE: ", 7);
				write(1, movements, sl_strlen(movements));
				write(1, "\n", 1);
				sl_check_elements_when_move(vars->l_start.y[0], vars->l_start.x[0], map, vars);
				sl_update_window(map, vars);
			}
}
