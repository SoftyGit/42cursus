/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:59:10 by yongjale          #+#    #+#             */
/*   Updated: 2023/02/21 00:44:04 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_update_window(char **map, t_vars *vars)
{
	int	row;
	int	col;

	sl_adjust_background(vars);
	row = 0;
	while (row < (vars->row_length))
	{
		col = 0;
		while (col < (vars->col_length))
		{
			if (map[row][col] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img3, col * 50, row * 50);
			else if (map[row][col] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img2, col * 50, row * 50);
			else if (map[row][col] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img4, col * 50, row * 50);
			col++;
		}
		row++;
	}
}

void	sl_adjust_background(t_vars *vars)
{
	int row;
	int	col;
	
	row = 0;
	while (row * BACKGROUND_ROW < vars->row_length)
	{
		col = 0;
		while (col * BACKGROUND_COL < vars->col_length)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img1, col * BACKGROUND_COL, row * BACKGROUND_ROW);
			col++;
		}
		row++;
	}
}

void	sl_control_hook(int keycode, t_vars	*vars)
{
		
}
