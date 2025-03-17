/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:43:57 by joaomart          #+#    #+#             */
/*   Updated: 2025/03/17 15:15:56 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	validate_imgs(t_game *info)
{
	if (!info->assets.player[0] || !info->assets.player[1]
		|| !info->assets.player[2] || !info->assets.player[3])
		ft_error_map(info, "Failed to load player images!");
	if (!info->assets.enemy[0] || !info->assets.enemy[1]
		|| !info->assets.enemy[2] || !info->assets.enemy[3])
		ft_error_map(info, "Failed to load enemy images!");
	if (!info->assets.collects[0] || !info->assets.collects[1]
		|| !info->assets.collects[2] || !info->assets.collects[3])
		ft_error_map(info, "Failed to load collectible images!");
	if (!info->assets.exit[0] || !info->assets.exit[1])
		ft_error_map(info, "Failed to load exit images!");
	if (!info->assets.floor || !info->assets.wall)
		ft_error_map(info, "Failed to load floor and wall images!");
}

void	put_imgs_map3(t_game *info, int x, int y)
{
	if (info->map_info.grid[y][x] == '1')
		mlx_put_image_to_window(info->mlx, info->window,
			info->assets.wall, x * 64, y * 64);
	else if (info->map_info.grid[y][x] == '0')
		mlx_put_image_to_window(info->mlx, info->window,
			info->assets.floor, x * 64, y * 64);
	else if (info->map_info.grid[y][x] == 'E')
		exit_type(info, x, y);
}

void	put_imgs_map2(t_game *info, int x, int y)
{
	if (info->map_info.grid[y][x] == 'X')
		mlx_put_image_to_window(info->mlx, info->window,
			info->assets.enemy[info->assets.frames.enemy_frame],
			x * 64, y * 64);
	else if (info->map_info.grid[y][x] == 'P')
		mlx_put_image_to_window(info->mlx, info->window,
			info->assets.player[info->assets.frames.player_frame],
			x * 64, y * 64);
	else if (info->map_info.grid[y][x] == 'C')
		mlx_put_image_to_window(info->mlx, info->window,
			info->assets.collects[info->assets.frames.collect_frame],
			x * 64, y * 64);
	else if (info->map_info.grid[y][x] == 'K')
		mlx_put_image_to_window(info->mlx, info->window,
			info->assets.explosion[info->assets.frames.explosion_frame],
			x * 64, y * 64);
	else
		put_imgs_map3(info, x, y);
}

void	put_imgs_map1(t_game *info)
{
	int		x;
	int		y;

	y = 0;
	while (y < info->map_info.height)
	{
		x = 0;
		while (info->map_info.grid[y][x])
		{
			put_imgs_map2(info, x, y);
			x++;
		}
		y++;
	}
}

int	update_game(void *param)
{
	t_game	*info;

	info = (t_game *)param;
	update_all_anim(info);
	put_imgs_map1(info);
	display_game_info(info);
	return (0);
}
