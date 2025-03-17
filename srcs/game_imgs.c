/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrade <andrade@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:43:57 by joaomart          #+#    #+#             */
/*   Updated: 2025/03/14 10:32:40 by andrade          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	validate_imgs(t_game *info)
{
	if (!info->assets.player)
		ft_error_map(info, "Failed to load player image!");
	if (!info->assets.collects)
		ft_error_map(info, "Failed to load collectible image!");
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
	if (info->map_info.grid[y][x] == 'P')
		mlx_put_image_to_window(info->mlx, info->window,
			info->assets.player,
			x * 64, y * 64);
	else if (info->map_info.grid[y][x] == 'C')
		mlx_put_image_to_window(info->mlx, info->window,
			info->assets.collects,
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
	put_imgs_map1(info);
	return (0);
}
