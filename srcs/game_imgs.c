/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:43:57 by joaomart          #+#    #+#             */
/*   Updated: 2025/03/11 20:10:36 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	validate_imgs(t_game *info)
{
	if (!info->assets.player[0] || !info->assets.player[1]
		|| !info->assets.player[2] || !info->assets.player[3])
		ft_error_map(info, "Falha ao carregar imagens do player!");
	if (!info->assets.enemy[0] || !info->assets.enemy[1]
		|| !info->assets.enemy[2] || !info->assets.enemy[3])
		ft_error_map(info, "Falha ao carregar imagens do enemy!");
	if (!info->assets.collects[0] || !info->assets.collects[1]
		|| !info->assets.collects[2] || !info->assets.collects[3])
		ft_error_map(info, "Falha ao carregar imagens do collectible!");
	if (!info->assets.exit[0] || !info->assets.exit[1])
		ft_error_map(info, "Falha ao carregar imagens da exit!");
	if (!info->assets.floor || !info->assets.wall)
		ft_error_map(info, "Falha ao carregar imagens do floor e wall!");
}

void	render_imgs(t_game *info, int x, int y)
{
	char	img;

	img = info->map_info.grid[y][x];
	if (img == '1')
		mlx_put_image_to_window(info->mlx, info->window,
			info->assets.wall, x * 64, y * 64);
	else if (img == '0')
		mlx_put_image_to_window(info->mlx, info->window,
			info->assets.floor, x * 64, y * 64);
	else if (img == 'P')
		mlx_put_image_to_window(info->mlx, info->window,
			info->assets.player[info->assets.player_frame], x * 64, y * 64);
	else if (img == 'C')
		mlx_put_image_to_window(info->mlx, info->window,
			info->assets.collects[info->assets.collect_frame], x * 64, y * 64);
	else if (img == 'X')
		mlx_put_image_to_window(info->mlx, info->window,
			info->assets.enemy[info->assets.enemy_frame], x * 64, y * 64);
	else if (img == 'E')
		mlx_put_image_to_window(info->mlx, info->window,
			info->assets.exit[info->assets.exit_frame % 2], x * 64, y * 64);
}

void	put_imgs_map2(t_game *info, int x, int y)
{
	if (info->map_info.grid[y][x] == 'X')
		mlx_put_image_to_window(info->mlx, info->window,
			info->assets.enemy[info->assets.enemy_frame],
			x * 64, y * 64);
	else if (info->map_info.grid[y][x] == 'P')
		mlx_put_image_to_window(info->mlx, info->window,
			info->assets.player[info->assets.player_frame],
			x * 64, y * 64);
	else if (info->map_info.grid[y][x] == 'C')
		mlx_put_image_to_window(info->mlx, info->window,
			info->assets.collects[info->assets.collect_frame],
			x * 64, y * 64);
	else
		render_imgs(info, x, y);
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

int	put_imgs(void *param)
{
	t_game	*info;

	info = (t_game *)param;
	update_all_anim(info);
	put_imgs_map1(info);
	return (0);
}
