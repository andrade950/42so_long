/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valiadate_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:35:50 by joaomart          #+#    #+#             */
/*   Updated: 2025/03/11 21:53:36 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	validate_collect(t_game *info, int x, int y)
{
	info->map_info.grid[y][x] = 'P';
	info->map_info.player_x = x;
	info->map_info.player_y = y;
	info->map_info.n_collects--;
	info->moves++;
	collect_message(info->map_info.n_collects);
}

int	validate_enemy(t_game *info)
{
	info_message("Perdeste! :X");
	free_game(info);
}

int	validate_exit(t_game *info, int x, int y)
{
	if (info->map_info.n_collects > 0)
	{
		info->map_info.grid[y][x] = 'P';
		info->map_info.player_x = x;
		info->map_info.player_y = y;
		info->moves++;
		return (0);
	}
	else
	{
		info_message("Terminaste o mapa! :D");
		free_game(info);
	}
	return (1);
}

int	validate_move(t_game *info, int x, int y)
{
	if (info->map_info.grid[y][x] == 'E')
		validate_exit(info, x, y);
	if (info->map_info.grid[y][x] == 'X')
		validate_enemy(info);
	if (info->map_info.grid[y][x] == 'C')
		validate_collect(info, x, y);
}
