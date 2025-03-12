/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:21:31 by joaomart          #+#    #+#             */
/*   Updated: 2025/03/11 20:12:22 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	open_window(t_game *info)
{
	int	window_width;
	int	window_height;

	window_width = (info->map_info.width - 1) * 64;
	window_height = info->map_info.height * 64;
	printf("Window: %d x %d\n", window_width, window_height);
	info->mlx = mlx_init();
	if (!info->mlx)
		ft_error_map(info, "Nao iniciou a Minilibx!");
	info->window = mlx_new_window(info->mlx,
			window_width, window_height, "so_long");
	if (!info->window)
		ft_error_map(info, "Nao foi possivel abrir a janela!");
}
