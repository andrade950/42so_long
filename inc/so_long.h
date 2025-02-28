/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrade <andrade@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:57:48 by joaomart          #+#    #+#             */
/*   Updated: 2025/02/28 17:11:26 by andrade          ###   ########.fr       */
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

typedef struct s_assets
{
	void	*player;
	void	*enemy;
	void	*collects;
	void	*exit;
	void	*floor;
	void	*wall;
}			t_assets;

typedef struct s_error
{
	int		temp_flag;
	int		player_foound;
	int		collectibles_found;
	int		exit_found;
}			t_error;

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
	t_error		error;
	t_map		map_info;
}				t_game;


//Functions args_checker.c
void	check_args(int ac, char *f_name);
void	check_ac(int ac);
void	check_filename(char *f_name);
void	check_map_exists(char *f_name);

//Functions validade_map.c
void	validate_map(t_map *map_info, char *f_name);

//Functions map.c
void	init_map(t_map *map, char *f_name);

//Functions map_infos.c
void	measure_lines(t_map *map_info, char *f_name);
void	validate_map_shape(t_map *map_info);

//Functions error.c
void	error();
void	error_fd(int fd);

//Extra
void	print_map(t_map *map_info);

#endif
