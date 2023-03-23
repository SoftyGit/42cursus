/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:41:06 by yongjale          #+#    #+#             */
/*   Updated: 2023/03/20 20:05:22 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_imgs	imgs;
	char	**map;

	if (argc != 2)
		sl_error(INPUT_ERR);
	sl_initialize_int_vars(&vars);
	map = sl_open_file(argv[1], &vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 50 * vars.col_length,
			50 * vars.row_length, "Kirby's Return to SO-LONG World!");
	vars.img1 = mlx_xpm_file_to_image(vars.mlx, "imgs/background.xpm",
			&imgs.back[0], &imgs.back[1]);
	vars.img2 = mlx_xpm_file_to_image(vars.mlx, "imgs/player.xpm",
			&imgs.back[0], &imgs.back[1]);
	vars.img3 = mlx_xpm_file_to_image(vars.mlx, "imgs/wall.xpm",
			&imgs.back[0], &imgs.back[1]);
	vars.img4 = mlx_xpm_file_to_image(vars.mlx, "imgs/cake.xpm",
			&imgs.back[0], &imgs.back[1]);
	vars.img5 = mlx_xpm_file_to_image(vars.mlx, "imgs/door.xpm",
			&imgs.back[0], &imgs.back[1]);
	sl_update_window(map, &vars);
	mlx_hook(vars.win, ON_KEY_PRESS, 0, sl_key_hook, &vars);
	mlx_hook(vars.win, ON_DESTROY, 0, sl_destroy_hook, &vars);
	mlx_loop(vars.mlx);
}

void	sl_initialize_int_vars(t_vars *vars)
{
	vars->map_recur = NULL;
	vars->row_length = 0;
	vars->col_length = 0;
	vars->move_records = 0;
	vars->prey_collect = 0;
	vars->l_start.amount = 0;
	vars->l_end.amount = 0;
	vars->l_start.amount = 0;
	vars->l_prey.amount = 0;
	vars->prey_collect = 0;
}

char	**sl_open_file(char *dir, t_vars *vars)
{
	int		fd;
	char	**map;

	fd = open(dir, O_RDONLY);
	if (fd == -1)
		sl_error(READ_ERR);
	vars->row_length = sl_count_line(fd);
	close(fd);
	fd = open(dir, O_RDONLY);
	map = sl_record_map(fd, vars->row_length);
	vars->map_addr = map;
	vars->col_length = sl_strlen(map[0]);
	sl_assign_mapdata(map, vars);
	sl_check_mapdata(map, vars);
	return (map);
}
