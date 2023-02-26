/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:59:10 by yongjale          #+#    #+#             */
/*   Updated: 2023/02/25 23:13:05 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	sl_check_elements_when_move(int row, int col, char **map, t_vars *vars)
{
	if (map[row][col] == 'C')
	{
		vars->prey_collect++;
		map[row][col] = '0';
	}
	else if (map[row][col] == 'E' && vars->prey_collect == vars->l_prey.amount)
	{
		exit(0);
	}
}

void	sl_update_window(char **map, t_vars *vars)
{
	int		row;
	int		col;

	sl_adjust_background(vars);
	row = 0;
	while (row < (vars->row_length))
	{
		col = 0;
		while (col < (vars->col_length))
		{
			if (map[row][col] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->img3, col * 50, row * 50);
			else if (map[row][col] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->img4, col * 50, row * 50);
			else if (map[row][col] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->img5, col * 50, row * 50);
			else if (map[row][col] == 'e')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->img6, col * 50, row * 50);
			col++;
		}
		row++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img2, vars->l_start.x[0] * 50, vars->l_start.y[0] * 50);
}

void	sl_adjust_background(t_vars *vars)
{
	int	row;
	int	col;

	row = 0;
	while (row * BACKGROUND_ROW < vars->row_length * 50)
	{
		col = 0;
		while (col * BACKGROUND_COL < vars->col_length * 50)
		{
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->img1, col * BACKGROUND_COL, row * BACKGROUND_ROW);
			col++;
		}
		row++;
	}
}
