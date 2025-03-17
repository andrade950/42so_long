/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:48:14 by joaomart          #+#    #+#             */
/*   Updated: 2025/03/17 15:10:47 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	destroy_imgs(t_game *info)
{
	if (info->assets.player)
		mlx_destroy_image(info->mlx, info->assets.player);
	if (info->assets.collects)
		mlx_destroy_image(info->mlx, info->assets.collects);
	if (info->assets.floor)
		mlx_destroy_image(info->mlx, info->assets.floor);
	if (info->assets.wall)
		mlx_destroy_image(info->mlx, info->assets.wall);
	if (info->assets.exit[0])
		mlx_destroy_image(info->mlx, info->assets.exit[0]);
	if (info->assets.exit[1])
		mlx_destroy_image(info->mlx, info->assets.exit[1]);
}

void	destroy_mlx(t_game *info)
{
	if (info->mlx)
	{
		destroy_imgs(info);
		if (info->window)
			mlx_destroy_window(info->mlx, info->window);
		mlx_destroy_display(info->mlx);
		free(info->mlx);
	}
}
