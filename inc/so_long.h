/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:57:48 by joaomart          #+#    #+#             */
/*   Updated: 2025/02/27 17:56:51 by joaomart         ###   ########.fr       */
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
	int			moves;
	bool		game_over;
	t_assets	assets;
	t_map		map;
}				t_game;


//Functions args_checker.c
void	check_args(int ac, char *str);
void	check_ac(int ac);
void	check_filename(char *str);
void	check_maps_exists(char *str);

//Functions map_checker.c
void	check_map_rect(char *map);

//Functions error.c
void	error();

#endif
