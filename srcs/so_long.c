/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:32:51 by joaomart          #+#    #+#             */
/*   Updated: 2025/03/17 15:15:25 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{
	t_game	info;

	ft_bzero(&info, sizeof(t_game));
	check_args(ac, av[1]);
	init_elements(&info);
	init_map(&info, av[1]);
	validate_map(&info, av[1]);
	open_window(&info);
	load_imgs(&info);
	mlx_key_hook(info.window, keys, &info);
	mlx_loop_hook(info.mlx, update_game, &info);
	mlx_hook(info.window, 17, 0, free_game, &info);
	mlx_loop(info.mlx);
	return (0);
}
