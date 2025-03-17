/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:35:09 by joaomart          #+#    #+#             */
/*   Updated: 2025/03/17 15:12:54 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	keys(int key, t_game *info)
{
	if (key == KEY_ESC)
		free_game(info);
	else if (key == KEY_W || key == KEY_UP
		|| key == KEY_A || key == KEY_LEFT
		|| key == KEY_S || key == KEY_DOWN
		|| key == KEY_D || key == KEY_RIGHT)
		move_player(info, key);
	return (1);
}
