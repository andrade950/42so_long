/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:24:41 by joaomart          #+#    #+#             */
/*   Updated: 2025/03/17 15:43:49 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	init_imgs(t_game *info)
{
	info->assets.player[0] = NULL;
	info->assets.player[1] = NULL;
	info->assets.player[2] = NULL;
	info->assets.player[3] = NULL;
	info->assets.enemy[0] = NULL;
	info->assets.enemy[1] = NULL;
	info->assets.enemy[2] = NULL;
	info->assets.enemy[3] = NULL;
	info->assets.collects[0] = NULL;
	info->assets.collects[1] = NULL;
	info->assets.collects[2] = NULL;
	info->assets.collects[3] = NULL;
	info->assets.exit[0] = NULL;
	info->assets.exit[1] = NULL;
	info->assets.floor = NULL;
	info->assets.wall = NULL;
}

void	init_frames(t_game *info)
{
	info->assets.frames.player_frame = 0;
	info->assets.frames.enemy_frame = 0;
	info->assets.frames.collect_frame = 0;
	info->assets.frames.exit_frame = 0;
	info->assets.frames.explosion_frame = 0;
	info->assets.frames.player_frame_counter = 0;
	info->assets.frames.enemy_frame_counter = 0;
	info->assets.frames.collect_frame_counter = 0;
	info->assets.frames.exit_frame_counter = 0;
	info->assets.frames.explosion_frame_counter = 0;
	info->assets.explosion_anim.active = 0;
	info->assets.explosion_anim.complete = 0;
	info->assets.explosion_anim.explosion_x = 0;
	info->assets.explosion_anim.explosion_y = 0;
}

void	init_explosion_imgs(t_game *info)
{
	int	i;

	i = 0;
	while (i < 12)
	{
		info->assets.explosion[i] = NULL;
		i++;
	}
}

void	init_elements(t_game *info)
{
	info->map_info.n_player = 0;
	info->map_info.n_collects = 0;
	info->map_info.n_enemy = 0;
	info->map_info.n_exit = 0;
	info->map_info.n_explosion = 0;
	info->moves = 0;
	info->lives = 3;
	info->map_info.width = 0;
	info->map_info.height = 0;
	info->map_info.player_x = 0;
	info->map_info.player_y = 0;
	info->mlx = NULL;
	info->window = NULL;
	info->map_info.grid = NULL;
	init_imgs(info);
	init_frames(info);
	init_explosion_imgs(info);
}

void	init_map(t_game *info, char *f_name)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	info->map_info.height = map_height(info, f_name);
	info->map_info.grid = ft_calloc(info->map_info.height + 1, sizeof(char *));
	if (!info->map_info.grid)
		ft_error_map(info, "Map allocation failed!");
	fd = open(f_name, O_RDONLY);
	if (fd < 0)
		ft_error_fd(fd, "File did not open!");
	line = get_next_line(fd);
	while (line && i < info->map_info.height)
	{
		if (!line)
			ft_error_map(info, "Error reading map line!");
		info->map_info.grid[i] = ft_strdup(line);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	info->map_info.grid[i] = NULL;
	close(fd);
}
