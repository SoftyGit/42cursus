/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_sprite_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:44:17 by yongjale          #+#    #+#             */
/*   Updated: 2023/09/28 14:12:56 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	sprite(int r, int c, t_vars *vars)
{
	int	i;

	i = 0;
	while (i <= 50)
	{
		if (r > 0)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img2,
				vars->l_start.x[0] * 50, (vars->l_start.y[0] - 1) * 50 + i);
		else if (r < 0)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img2,
				vars->l_start.x[0] * 50, (vars->l_start.y[0] + 1) * 50 - i);
		else if (c > 0)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img2,
				(vars->l_start.x[0] - 1) * 50 + i, vars->l_start.y[0] * 50);
		else if (c < 0)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img2,
				(vars->l_start.x[0] + 1) * 50 - i, vars->l_start.y[0] * 50);
		mlx_do_sync(vars->mlx);
		i += 10;
	}
}

static void	sl_split_up_window(int row, int col, char **map, t_vars *vars)
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
	else if (map[row][col] == 'M')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img6, col * 50, row * 50);
}

void	sl_up_window(int r, int c, char **map, t_vars *vars)
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
			sl_split_up_window(row, col, map, vars);
			col++;
		}
		row++;
	}
	sprite(r, c, vars);
}
