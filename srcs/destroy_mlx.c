/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:48:14 by joaomart          #+#    #+#             */
/*   Updated: 2025/03/11 19:52:56 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	destroy_p(t_game *info)
{
	mlx_destroy_image(info->mlx, info->assets.player[0]);
	mlx_destroy_image(info->mlx, info->assets.player[1]);
	mlx_destroy_image(info->mlx, info->assets.player[2]);
	mlx_destroy_image(info->mlx, info->assets.player[3]);
}

void	destroy_e(t_game *info)
{
	mlx_destroy_image(info->mlx, info->assets.enemy[0]);
	mlx_destroy_image(info->mlx, info->assets.enemy[1]);
	mlx_destroy_image(info->mlx, info->assets.enemy[2]);
	mlx_destroy_image(info->mlx, info->assets.enemy[3]);
}

void	destroy_c(t_game *info)
{
	mlx_destroy_image(info->mlx, info->assets.collects[0]);
	mlx_destroy_image(info->mlx, info->assets.collects[1]);
	mlx_destroy_image(info->mlx, info->assets.collects[2]);
	mlx_destroy_image(info->mlx, info->assets.collects[3]);
}

void	destroy_fwe(t_game *info)
{
	mlx_destroy_image(info->mlx, info->assets.floor);
	mlx_destroy_image(info->mlx, info->assets.wall);
	mlx_destroy_image(info->mlx, info->assets.exit[0]);
	mlx_destroy_image(info->mlx, info->assets.exit[1]);
}

void	destroy_mlx(t_game *info)
{
	destroy_p(info);
	destroy_e(info);
	destroy_c(info);
	destroy_fwe(info);
	mlx_clear_window(info->mlx, info->window);
	mlx_destroy_display(info->mlx);
	free(info->mlx);
}
