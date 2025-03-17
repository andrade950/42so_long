/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:43:01 by andrade           #+#    #+#             */
/*   Updated: 2025/03/17 15:16:14 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	game_over(t_game *info, char *msg)
{
	ft_printf("\n======== GAME OVER =========\n");
	ft_printf("%s\n", msg);
	ft_printf("============================\n\n");
	free_game(info);
}

void	win_game(t_game *info)
{
	ft_printf("\n==== YOU WIN! ====\n");
	ft_printf("Congratulations!\n");
	ft_printf("Total moves: %d\n", info->moves);
	ft_printf("==================\n\n");
	free_game(info);
}

void	display_game_info(t_game *info)
{
	char	*moves_str;
	char	*collects_str;
	char	*lives_str;

	moves_str = ft_itoa(info->moves);
	collects_str = ft_itoa(info->map_info.n_collects);
	lives_str = ft_itoa(info->lives);
	mlx_string_put(info->mlx, info->window, 10, 20, 0xFFFFFF, "Moves:");
	mlx_string_put(info->mlx, info->window, 60, 20, 0xFFFFFF, moves_str);
	mlx_string_put(info->mlx, info->window, 10, 40, 0xFFFFFF, "Collectibles:");
	mlx_string_put(info->mlx, info->window, 110, 40, 0xFFFFFF, collects_str);
	mlx_string_put(info->mlx, info->window, 10, 60, 0xFFFFFF, "Lives:");
	mlx_string_put(info->mlx, info->window, 60, 60, 0xFFFFFF, lives_str);
	free(moves_str);
	free(collects_str);
	free(lives_str);
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
