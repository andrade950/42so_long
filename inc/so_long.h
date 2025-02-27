/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:57:48 by joaomart          #+#    #+#             */
/*   Updated: 2025/02/26 21:38:55 by joaomart         ###   ########.fr       */
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
	char	**map;
	int		map_len;
	int		n_player;
	int		n_collects;
	int		n_enemy;
	int		n_exit;
}			t_map;

typedef struct s_player
{
	int		x_pos;
	int		y_pos;
}			t_player;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	t_assets	assets;
	t_map		map;
	t_player	player;
}				t_game;


//Functions checks.c
void	check_ac(int ac);
void	check_filename(char *str);

#endif
