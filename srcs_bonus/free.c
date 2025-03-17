/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrade <andrade@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:42:38 by joaomart          #+#    #+#             */
/*   Updated: 2025/03/13 10:43:36 by andrade          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	free_map(t_map *map_info)
{
	int	i;

	if (!map_info || !map_info->grid)
		return ;
	i = 0;
	while (i < map_info->height)
	{
		if (map_info->grid[i])
			free(map_info->grid[i]);
		i++;
	}
	free(map_info->grid);
	map_info->grid = NULL;
}

int	free_game(t_game *info)
{
	free_map(&info->map_info);
	destroy_mlx(info);
	exit(0);
}
