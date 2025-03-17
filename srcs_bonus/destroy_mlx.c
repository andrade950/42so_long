/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrade <andrade@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:48:14 by joaomart          #+#    #+#             */
/*   Updated: 2025/03/14 15:54:50 by andrade          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	destroy_pe(t_game *info)
{
	mlx_destroy_image(info->mlx, info->assets.player[0]);
	mlx_destroy_image(info->mlx, info->assets.player[1]);
	mlx_destroy_image(info->mlx, info->assets.player[2]);
	mlx_destroy_image(info->mlx, info->assets.player[3]);
	mlx_destroy_image(info->mlx, info->assets.enemy[0]);
	mlx_destroy_image(info->mlx, info->assets.enemy[1]);
	mlx_destroy_image(info->mlx, info->assets.enemy[2]);
	mlx_destroy_image(info->mlx, info->assets.enemy[3]);
}

void	destroy_e(t_game *info)
{
	int	i;

	i = 0;
	while (i < 12)
	{
		mlx_destroy_image(info->mlx, info->assets.explosion[i]);
		i++;
	}
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
	if (info->mlx)
	{
		if (info->assets.player[0] && info->assets.enemy[0])
			destroy_pe(info);
		if (info->assets.collects[0])
			destroy_c(info);
		if (info->assets.explosion[0])
			destroy_e(info);
		if (info->assets.floor && info->assets.wall && info->assets.exit[0])
			destroy_fwe(info);
		if (info->window)
			mlx_destroy_window(info->mlx, info->window);
		mlx_destroy_display(info->mlx);
		free(info->mlx);
	}
}
