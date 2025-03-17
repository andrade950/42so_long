/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrade <andrade@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:16:27 by joaomart          #+#    #+#             */
/*   Updated: 2025/03/13 10:44:09 by andrade          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	load_player_imgs(t_game *info, int width, int height)
{
	info->assets.player[0] = mlx_xpm_file_to_image(info->mlx,
			"assets/player1.xpm", &width, &height);
	info->assets.player[1] = mlx_xpm_file_to_image(info->mlx,
			"assets/player2.xpm", &width, &height);
	info->assets.player[2] = mlx_xpm_file_to_image(info->mlx,
			"assets/player3.xpm", &width, &height);
	info->assets.player[3] = mlx_xpm_file_to_image(info->mlx,
			"assets/player4.xpm", &width, &height);
}

void	load_enemy_imgs(t_game *info, int width, int height)
{
	info->assets.enemy[0] = mlx_xpm_file_to_image(info->mlx,
			"assets/enemy1.xpm", &width, &height);
	info->assets.enemy[1] = mlx_xpm_file_to_image(info->mlx,
			"assets/enemy2.xpm", &width, &height);
	info->assets.enemy[2] = mlx_xpm_file_to_image(info->mlx,
			"assets/enemy3.xpm", &width, &height);
	info->assets.enemy[3] = mlx_xpm_file_to_image(info->mlx,
			"assets/enemy4.xpm", &width, &height);
}

void	load_collect_imgs(t_game *info, int width, int height)
{
	info->assets.collects[0] = mlx_xpm_file_to_image(info->mlx,
			"assets/collectible1.xpm", &width, &height);
	info->assets.collects[1] = mlx_xpm_file_to_image(info->mlx,
			"assets/collectible2.xpm", &width, &height);
	info->assets.collects[2] = mlx_xpm_file_to_image(info->mlx,
			"assets/collectible3.xpm", &width, &height);
	info->assets.collects[3] = mlx_xpm_file_to_image(info->mlx,
			"assets/collectible4.xpm", &width, &height);
}

void	load_fwe_imgs(t_game *info, int width, int height)
{
	info->assets.floor = mlx_xpm_file_to_image(info->mlx,
			"assets/floor.xpm", &width, &height);
	info->assets.wall = mlx_xpm_file_to_image(info->mlx,
			"assets/wall.xpm", &width, &height);
	info->assets.exit[0] = mlx_xpm_file_to_image(info->mlx,
			"assets/exit0.xpm", &width, &height);
	info->assets.exit[1] = mlx_xpm_file_to_image(info->mlx,
			"assets/exit1.xpm", &width, &height);
}

void	load_imgs(t_game *info)
{
	int	width;
	int	height;

	width = 64;
	height = 64;
	load_player_imgs(info, width, height);
	load_enemy_imgs(info, width, height);
	load_collect_imgs(info, width, height);
	load_fwe_imgs(info, width, height);
	validate_imgs(info);
	load_explosion_imgs(info, width, height);
	validate_explosion_imgs(info);
}
