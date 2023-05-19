/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:56:29 by yongjale          #+#    #+#             */
/*   Updated: 2023/05/18 21:48:33 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define MAX_AMOUNT 1024

typedef struct s_locations{
	int	amount;
	int	x[MAX_AMOUNT];
	int	y[MAX_AMOUNT];
}	t_locations;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	void		*img1;
	void		*img2;
	void		*img3;
	void		*img4;
	void		*img5;
	char		**map_addr;
	char		*map_recur;
	int			row_length;
	int			col_length;
	int			move_records;
	int			prey_collect;
	t_locations	l_start;
	t_locations	l_end;
	t_locations	l_prey;
}	t_vars;

typedef struct s_imgs {
	int		back[2];
}	t_imgs;

enum e_KEY{
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_ESC = 53,
};
enum e_ON{
	ON_KEY_PRESS = 2,
	ON_DESTROY = 17
};
enum e_ERROR{
	MALLOC_ERR = -1,
	INPUT_ERR = 10,
	READ_ERR = 11,
	NON_MAP_ERR = 20,
	NON_RECT_MAP_ERR = 21,
	NON_SURROUNG_WALL_MAP_ERR = 22,
	NON_VALID_PATH_FROM_PLAYER_TO_PREY = 23,
	INVALID_WALL_MAP_ERR = 32,
	INVALID_ELEMENTS_MAP_ERR = 33,
	INVALID_PLAYER_ELEMENT_MAP_ERR = 34,
	INVALID_ESCAPE_ELEMENT_MAP_ERR = 35,
	INVALID_PREY_ELEMENT_MAP_ERR = 36
};

# define BACKGROUND_ROW 500
# define BACKGROUND_COL 800

void	sl_initialize_int_vars(t_vars *vars);
char	**sl_open_file(char	*dir, t_vars *vars);
int		sl_key_hook(int keycode, t_vars *vars);
int		sl_destroy_hook(t_vars *vars);
void	sl_control_hook(int keycode, t_vars *vars);
int		sl_count_line(int fd);
char	**sl_record_map(int fd, int length);
void	sl_record_mapdata(char **map, int row, int col, t_vars *vars);
void	sl_assign_mapdata(char **map, t_vars *vars);
int		sl_strncmp(const char *s1, const char *s2, size_t n);
size_t	sl_strlen(const char *s);
char	*sl_itoa(int n);
void	sl_error(int code);
void	sl_check_mapdata(char **map, t_vars *vars);
void	sl_check_elements_when_move(int row, int col, char **map, t_vars *vars);
void	sl_check_valid_path(int num, char **map, t_vars *vars);
int		sl_check_valid_recur(int row, int col, t_vars *vars, int status);
int		sl_recur_prey(int row, int col, char **map, t_vars *vars);
void	sl_update_window(char **map, t_vars *vars);
void	sl_adjust_background(t_vars *vars);
void	sl_move_player(int row_var, int col_var, t_vars *vars);
void	sl_free(int err_num, char **map);

#endif