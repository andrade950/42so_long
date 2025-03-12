/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:35:09 by joaomart          #+#    #+#             */
/*   Updated: 2025/03/11 21:36:45 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	move_up(t_game *info)
{
	int	x;
	int	y;
	int	valid;

	x = info->map_info.player_x;
	y = (info->map_info.player_y) = 1;
	if (info->map_info.grid[y][x] == '1')
		return (0);
	valid = validate_move(info, x, y);
}

int	moves(int key, t_game *info)
{
	int	can_move;

	if (key == KEY_ESC)
		free_game(info);
	if (key == KEY_W || key == KEY_UP)
		can_move = move_up(info);
	return (1);
}
