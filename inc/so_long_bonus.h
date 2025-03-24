/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:57:48 by joaomart          #+#    #+#             */
/*   Updated: 2025/03/17 15:44:12 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libs/libft/libft.h"
# include "../libs/ft_printf/include/ft_printf.h"
# include "../libs/get_next_line/inc/get_next_line.h"
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/minilibx-linux/mlx_int.h"
# include <time.h>

//Keys
# define KEY_ESC XK_Escape
# define KEY_W XK_w
# define KEY_A XK_a
# define KEY_S XK_s
# define KEY_D XK_d
# define KEY_UP XK_Up
# define KEY_LEFT XK_Left
# define KEY_DOWN XK_Down
# define KEY_RIGHT XK_Right

typedef struct s_explosion
{
	int		active;
	int		explosion_x;
	int		explosion_y;
	int		complete;
}			t_explosion;

typedef struct s_frame
{
	int			player_frame;
	int			player_frame_counter;
	int			enemy_frame;
	int			enemy_frame_counter;
	int			collect_frame;
	int			collect_frame_counter;
	int			exit_frame;
	int			exit_frame_counter;
	int			explosion_frame;
	int			explosion_frame_counter;
}				t_frame;

typedef struct s_assets
{
	void		*player[4];
	void		*enemy[4];
	void		*collects[4];
	void		*exit[2];
	void		*floor;
	void		*wall;
	void		*explosion[12];
	t_frame		frames;
	t_explosion	explosion_anim;
}				t_assets;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		n_player;
	int		n_collects;
	int		n_enemy;
	int		n_exit;
	int		n_explosion;
	int		player_x;
	int		player_y;
}			t_map;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	int			moves;
	int			lives;
	t_assets	assets;
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
int		map_height(t_game *info, char *f_name);
void	validate_map_shape(t_game *info);
void	validate_map_walls(t_game *info);

//Functions init_map.c
void	init_map(t_game *info, char *f_name);
void	init_elements(t_game *info);
void	init_imgs(t_game *info);
void	init_frames(t_game *info);
void	init_explosion_imgs(t_game *info);

//Functions init_game.c
void	open_window(t_game *info);

//Functions elements_map.c
void	player_pos(t_game *info, int x, int y);
void	coor_maps(t_game *info);
void	count_elements(t_game *info, int end_x, int end_y);
int		unknown_element(t_game *info, int x, int y);
void	n_of_elements(t_game *info);

//Functions game_imgs.c
void	validate_imgs(t_game *info);
void	put_imgs_map1(t_game *info);
void	put_imgs_map2(t_game *info, int x, int y);
void	put_imgs_map3(t_game *info, int x, int y);
int		update_game(void *param);

//Functions load_imgs.c
void	load_imgs(t_game *info);
void	load_player_imgs(t_game *info, int width, int height);
void	load_enemy_imgs(t_game *info, int width, int height);
void	load_collect_imgs(t_game *info, int width, int height);
void	load_fwe_imgs(t_game *info, int width, int height);

//Functions img_animation.c
void	update_player_animation(t_game *info);
void	update_enemy_animation(t_game *info);
void	update_collect_animation(t_game *info);
long	get_current_time_ms(void);
void	update_all_anim(t_game *info);

//Functions flood_fill.c
void	validate_coor(t_game *info);
void	validate_map_access(t_game *info);
char	**copy_map(t_game *info);
void	elements_locked(t_game *info, char **map_copy, int i);
void	flood_fill(char **map_copy, int px, int py);

//Functions key.c
int		keys(int key, t_game *info);

//Functions player_moves.c
void	move_player(t_game *info, int key);
int		valid_move(t_game *info, int next_x, int next_y);
void	update_player_pos(t_game *info, int next_x, int next_y);
void	pos_x(t_game *info, int next_x, int next_y);

//Functions player_death.c
void	load_explosion_imgs(t_game *info, int width, int height);
void	validate_explosion_imgs(t_game *info);
void	update_explosion_animation(t_game *info);

//Functions game_state.c
void	display_game_info(t_game *info);
void	win_game(t_game *info);
void	game_over(t_game *info, char *msg);
void	exit_type(t_game *info, int x, int y);

//Functions destroy_mlx.c
void	destroy_mlx(t_game *info);
void	destroy_pe(t_game *info);
void	destroy_e(t_game *info);
void	destroy_c(t_game *info);
void	destroy_fwe(t_game *info);

//Functions free.c
void	free_map(t_map *map_info);
int		free_game(t_game *info);

//Functions error.c
void	ft_error(char *msg);
void	ft_error_map(t_game *info, char *msg);
void	ft_error_fd(int fd, char *msg);

#endif
