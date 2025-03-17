/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:23:39 by joaomart          #+#    #+#             */
/*   Updated: 2025/03/17 15:11:10 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	player_pos(t_game *info, int x, int y)
{
	info->map_info.n_player++;
	info->map_info.player_x = x;
	info->map_info.player_y = y;
}

int	unknown_element(t_game *info, int x, int y)
{
	if (info->map_info.grid[y][x] != '1' && info->map_info.grid[y][x] != '0'
		&& info->map_info.grid[y][x] != 'P' && info->map_info.grid[y][x] != 'C'
		&& info->map_info.grid[y][x] != 'E'
		&& info->map_info.grid[y][x] != '\n')
	{
		return (1);
	}
	else
		return (0);
}

void	n_of_elements(t_game *info)
{
	if (info->map_info.n_player != 1)
		ft_error_map(info, "Wrong number of players!");
	if (info->map_info.n_exit != 1)
		ft_error_map(info, "Wrong number of exits!");
	if (info->map_info.n_collects == 0)
		ft_error_map(info, "Insufficient number of collectibles!");
}

void	count_elements(t_game *info, int end_x, int end_y)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x <= end_x)
	{
		y = 0;
		while (y <= end_y)
		{
			if (info->map_info.grid[y][x] == 'P')
				player_pos(info, x, y);
			else if (info->map_info.grid[y][x] == 'C')
				info->map_info.n_collects++;
			else if (info->map_info.grid[y][x] == 'E')
				info->map_info.n_exit++;
			if (unknown_element(info, x, y))
				ft_error_map(info, "Invalid elements!");
			y++;
		}
		x++;
	}
}

void	coor_maps(t_game *info)
{
	int	end_x;
	int	end_y;

	end_x = info->map_info.width - 1;
	end_y = info->map_info.height - 1;
	count_elements(info, end_x, end_y);
}
