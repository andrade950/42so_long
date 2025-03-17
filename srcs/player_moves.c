/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:27:09 by andrade           #+#    #+#             */
/*   Updated: 2025/03/17 15:14:53 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	valid_move(t_game *info, int next_x, int next_y)
{
	char	next_pos;

	next_pos = info->map_info.grid[next_y][next_x];
	if (next_pos == '1')
		return (0);
	if (next_pos == 'E')
	{
		if (info->map_info.n_collects == 0)
		{
			win_game(info);
			return (0);
		}
		else
		{
			ft_printf("Collect all items first! %d remaining.\n",
				info->map_info.n_collects);
			return (0);
		}
	}
	return (1);
}

void	update_player_pos(t_game *info, int next_x, int next_y)
{
	int	curr_x;
	int	curr_y;

	curr_x = info->map_info.player_x;
	curr_y = info->map_info.player_y;
	if (info->map_info.grid[next_y][next_x] == 'C')
	{
		info->map_info.n_collects--;
		ft_printf("Collectible found! %d remaining.\n",
			info->map_info.n_collects);
		if (info->map_info.n_collects == 0)
			ft_printf("Now you can exit the map!\n");
	}
	info->map_info.grid[curr_y][curr_x] = '0';
	info->map_info.grid[next_y][next_x] = 'P';
	info->map_info.player_x = next_x;
	info->map_info.player_y = next_y;
	info->moves++;
	ft_printf("Moves: %d\n", info->moves);
}

void	move_player(t_game *info, int key)
{
	int	next_x;
	int	next_y;

	next_x = info->map_info.player_x;
	next_y = info->map_info.player_y;
	if (key == KEY_W || key == KEY_UP)
		next_y--;
	else if (key == KEY_S || key == KEY_DOWN)
		next_y++;
	else if (key == KEY_A || key == KEY_LEFT)
		next_x--;
	else if (key == KEY_D || key == KEY_RIGHT)
		next_x++;
	if (valid_move(info, next_x, next_y))
		update_player_pos(info, next_x, next_y);
}
