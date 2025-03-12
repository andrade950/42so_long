/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_animation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:51:31 by joaomart          #+#    #+#             */
/*   Updated: 2025/03/11 21:09:48 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

long	get_current_time_ms(void)
{
	return ((clock() * 1000) / CLOCKS_PER_SEC);
}

void	update_player_animation(t_game *info)
{
	static long	last_update_time = 0;
	long		current_time;
	long		elapsed_time;

	current_time = get_current_time_ms();
	if (last_update_time == 0)
		last_update_time = current_time;
	elapsed_time = current_time - last_update_time;
	if (elapsed_time >= 25)
	{
		info->assets.player_frame = (info->assets.player_frame + 1) % 4;
		last_update_time = current_time;
	}
}

void	update_enemy_animation(t_game *info)
{
	static long	last_update_time = 0;
	long		current_time;
	long		elapsed_time;

	current_time = get_current_time_ms();
	if (last_update_time == 0)
		last_update_time = current_time;
	elapsed_time = current_time - last_update_time;
	if (elapsed_time >= 105)
	{
		info->assets.enemy_frame = (info->assets.enemy_frame + 1) % 4;
		last_update_time = current_time;
	}
}

void	update_collect_animation(t_game *info)
{
	static long	last_update_time = 0;
	long		current_time;
	long		elapsed_time;

	current_time = get_current_time_ms();
	if (last_update_time == 0)
		last_update_time = current_time;
	elapsed_time = current_time - last_update_time;
	if (elapsed_time >= 45)
	{
		info->assets.collect_frame = (info->assets.collect_frame + 1) % 4;
		last_update_time = current_time;
	}
}

void	update_all_anim(t_game *info)
{
	update_player_animation(info);
	update_enemy_animation(info);
	update_collect_animation(info);
}
