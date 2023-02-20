/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:56:29 by yongjale          #+#    #+#             */
/*   Updated: 2023/02/21 00:43:39 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct	s_locations{
	int	amount;
	int	*x;
	int	*y;
}	t_locations;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
	void		*img1;
	void		*img2;
	void		*img3;
	void		*img4;
	int			row_length;
	int			col_length;
	t_locations	l_player;
	t_locations	l_start;
	t_locations l_end;
	t_locations	l_prey;
}	t_vars;

typedef struct	s_imgs {
	int		back[2];
	int		cake[2];
	int		obj[2];
}	t_imgs;

enum KEY{
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_ESC = 53,
};
enum ON{
	ON_KEY_PRESS = 2,
	ON_DESTROY = 17
};
enum ERROR{
	MALLOC_ERR = -1,
	INPUT_ERR = 10,
	READ_ERR = 11,
	NON_MAP_ERR = 20,
	NON_RECT_MAP_ERR = 21,
	INVALID_WALL_MAP_ERR = 22,
	INVALID_ELEMENTS_MAP_ERR = 23,
	INVALID_PLAYER_ELEMENT_MAP_ERR = 24,
	INVALID_ESCAPE_ELEMENT_MAP_ERR = 25,
	INVALID_PREY_ELEMENT_MAP_ERR = 26
};

# define BACKGROUND_ROW 500
# define BACKGROUND_COL 800

char	**sl_open_file(char	*dir, t_vars *vars);
int		sl_key_hook(int keycode, t_vars *vars);
int		sl_destroy_hook(int keycode, t_vars *vars);
void	sl_control_hook(int keycode, t_vars *vars);
int		sl_count_line(int fd);
char	**sl_record_map(int fd, int length);
void	sl_assign_mapdata(char **map, t_vars *vars);
size_t	sl_strlen(const char *s);
void	sl_error(int code);
void	sl_check_mapdata(char **map, t_vars *vars);
void	sl_update_window(char **map, t_vars *vars);
void	sl_adjust_background(t_vars *vars);
