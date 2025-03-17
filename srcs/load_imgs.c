/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:16:27 by joaomart          #+#    #+#             */
/*   Updated: 2025/03/17 15:14:01 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	load_all_imgs(t_game *info, int width, int height)
{
	info->assets.player = mlx_xpm_file_to_image(info->mlx,
			"assets/player1.xpm", &width, &height);
	info->assets.collects = mlx_xpm_file_to_image(info->mlx,
			"assets/collectible1.xpm", &width, &height);
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
	load_all_imgs(info, width, height);
	validate_imgs(info);
}
