/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrade <andrade@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:57:48 by joaomart          #+#    #+#             */
/*   Updated: 2025/03/07 17:23:16 by andrade          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/libft.h"
# include "../libs/ft_printf/include/ft_printf.h"
# include "../libs/get_next_line/inc/get_next_line.h"
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/minilibx-linux/mlx_int.h"
# include <fcntl.h>
# include <stdbool.h>

# define KEY_ESC 65307
# define KEY_Q 113

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

# define TILE_SIZE 64

typedef struct s_assets
{
	void	*player;
	void	*enemy;
	void	*collects;
	void	*exit;
	void	*floor;
	void	*wall;
}			t_assets;

typedef struct s_found
{
	int		temp_flag;
	int		player_found;
	int		collectibles_found;
	int		exit_found;
}			t_found;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		n_player;
	int		n_collects;
	int		n_enemy;
	int		n_exit;
	int		player_x;
	int		player_y;
}			t_map;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	int			signal;
	int			window_x;
	int			window_y;
	int			moves;
	bool		game_over;
	int			exit_flag;
	t_assets	assets;
	t_found		found;
	t_map		map_info;
}				t_game;


//Functions args_checker.c
void	check_args(int ac, char *f_name);
void	check_ac(int ac);
void	check_filename(char *f_name);
void	check_map_exists(char *f_name);

//Functions validade_map.c
void	validate_map(t_game *info, char *f_name);
void	validate_map_elements(t_game *info);
int		measure_lines(t_game *info, char *f_name);
void	validate_map_shape(t_game *info);
void	validate_map_walls(t_game *info);

//Functions init_game.c
void	init_map(t_game *info, char *f_name);
void	init_elements(t_game *info);

//Functions init_game.c
void	open_window(t_game *info);

//Functions elements_map.c
void	player_pos(t_game *info, int x, int y);
void	coor_maps(t_game *info);
void	count_elements(t_game *info, int end_x, int end_y);
int		unknown_element(t_game *info, int x, int y);
void	n_of_elements(t_game *info);

//Functions error.c
void	error(char *msg);
void	error_fd(int fd, char *msg);

//Extra
void	print_map(t_game *info);

#endif
