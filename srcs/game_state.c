/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:43:01 by andrade           #+#    #+#             */
/*   Updated: 2025/03/17 15:11:53 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	win_game(t_game *info)
{
	ft_printf("\n==== YOU WIN! ====\n");
	ft_printf("Congratulations!\n");
	ft_printf("Total moves: %d\n", info->moves);
	ft_printf("==================\n\n");
	free_game(info);
}

void	exit_type(t_game *info, int x, int y)
{
	if (info->map_info.n_collects > 0)
		mlx_put_image_to_window(info->mlx, info->window,
			info->assets.exit[0], x * 64, y * 64);
	else
		mlx_put_image_to_window(info->mlx, info->window,
			info->assets.exit[1], x * 64, y * 64);
}
