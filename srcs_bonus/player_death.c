/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_death.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:51:10 by andrade           #+#    #+#             */
/*   Updated: 2025/03/17 15:18:59 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	load_explosion_imgs(t_game *info, int width, int height)
{
	info->assets.explosion[0] = mlx_xpm_file_to_image(info->mlx,
			"assets/explosion1.xpm", &width, &height);
	info->assets.explosion[1] = mlx_xpm_file_to_image(info->mlx,
			"assets/explosion2.xpm", &width, &height);
	info->assets.explosion[2] = mlx_xpm_file_to_image(info->mlx,
			"assets/explosion3.xpm", &width, &height);
	info->assets.explosion[3] = mlx_xpm_file_to_image(info->mlx,
			"assets/explosion4.xpm", &width, &height);
	info->assets.explosion[4] = mlx_xpm_file_to_image(info->mlx,
			"assets/explosion5.xpm", &width, &height);
	info->assets.explosion[5] = mlx_xpm_file_to_image(info->mlx,
			"assets/explosion6.xpm", &width, &height);
	info->assets.explosion[6] = mlx_xpm_file_to_image(info->mlx,
			"assets/explosion7.xpm", &width, &height);
	info->assets.explosion[7] = mlx_xpm_file_to_image(info->mlx,
			"assets/explosion8.xpm", &width, &height);
	info->assets.explosion[8] = mlx_xpm_file_to_image(info->mlx,
			"assets/explosion9.xpm", &width, &height);
	info->assets.explosion[9] = mlx_xpm_file_to_image(info->mlx,
			"assets/explosion10.xpm", &width, &height);
	info->assets.explosion[10] = mlx_xpm_file_to_image(info->mlx,
			"assets/explosion11.xpm", &width, &height);
	info->assets.explosion[11] = mlx_xpm_file_to_image(info->mlx,
			"assets/explosion12.xpm", &width, &height);
}

void	validate_explosion_imgs(t_game *info)
{
	if (!info->assets.explosion[0] || !info->assets.explosion[1]
		|| !info->assets.explosion[2] || !info->assets.explosion[3]
		|| !info->assets.explosion[4] || !info->assets.explosion[5]
		|| !info->assets.explosion[6] || !info->assets.explosion[7]
		|| !info->assets.explosion[8] || !info->assets.explosion[9]
		|| !info->assets.explosion[10] || !info->assets.explosion[11])
		ft_error_map(info, "Falha ao carregar imagens da explosao!");
}

void	update_explosion_animation(t_game *info)
{
	static long	last_update_time = 0;
	long		current_time;
	long		elapsed_time;

	if (!info->assets.explosion_anim.active)
		return ;
	current_time = get_current_time_ms();
	if (last_update_time == 0)
		last_update_time = current_time;
	elapsed_time = current_time - last_update_time;
	if (elapsed_time >= 45)
	{
		info->assets.frames.explosion_frame++;
		if (info->assets.frames.explosion_frame >= 12)
		{
			info->map_info.grid[info->assets.explosion_anim.explosion_y]
			[info->assets.explosion_anim.explosion_x] = '0';
			info->assets.explosion_anim.active = 0;
			info->assets.explosion_anim.complete = 1;
			info->assets.frames.explosion_frame = 0;
		}
		last_update_time = current_time;
	}
}
