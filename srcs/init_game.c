/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrade <andrade@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:21:31 by joaomart          #+#    #+#             */
/*   Updated: 2025/03/07 17:32:11 by andrade          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	open_window(t_game *info)
{
	int window_width = (info->map_info.width - 1) * 64;
	int window_height = info->map_info.height * 64;
	printf("Attempting to create window: %d x %d\n", window_width, window_height);

	info->mlx = mlx_init();
	if (!info->mlx)
		error("Nao iniciou a Minilibx!");
	info->window = mlx_new_window(info->mlx, window_width, window_height, "so_long");
	if (!info->window)
	{
		mlx_destroy_display(info->mlx);
		free(info->mlx);
		error("Nao foi possivel abrir a janela!");
	}
}
