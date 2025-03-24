/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrade <andrade@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:19:54 by joaomart          #+#    #+#             */
/*   Updated: 2025/03/19 12:12:35 by andrade          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	validate_coor(t_game *info)
{
	if (info->map_info.player_x < 0
		|| info->map_info.player_x >= info->map_info.width
		|| info->map_info.player_y < 0
		|| info->map_info.player_y >= info->map_info.height)
		ft_error_map(info, "Invalid coordinates!");
}

char	**copy_map(t_game *info)
{
	char	**map_copy;
	int		i;

	i = 0;
	map_copy = (char **)ft_calloc(info->map_info.height + 1, sizeof(char *));
	if (!map_copy)
		ft_error_map(info, "Failed to copy map!");
	while (i < info->map_info.height)
	{
		map_copy[i] = ft_strdup(info->map_info.grid[i]);
		if (map_copy[i] == NULL)
		{
			while (i > 0)
				free(map_copy[--i]);
			free(map_copy);
			return (NULL);
		}
		i++;
	}
	return (map_copy);
}

void	flood_fill(char **map_copy, int px, int py)
{
	if (px < 0 || py < 0 || map_copy[py][px] == '1'
		|| map_copy[py][px] == 'X' || map_copy[py][px] == 'F')
		return ;
	if (map_copy[py][px] == 'E')
	{
		map_copy[py][px] = 'F';
		return ;
	}
	if (map_copy[py][px] == '0' || map_copy[py][px] == 'P'
		|| map_copy[py][px] == 'C')
		map_copy[py][px] = 'F';
	flood_fill(map_copy, px + 1, py);
	flood_fill(map_copy, px - 1, py);
	flood_fill(map_copy, px, py + 1);
	flood_fill(map_copy, px, py - 1);
}

void	elements_locked(t_game *info, char **map_copy, int i)
{
	int	j;

	j = 0;
	while (map_copy[i][j])
	{
		if (map_copy[i][j] == 'E' || map_copy[i][j] == 'C')
		{
			while (map_copy[i])
				free(map_copy[i++]);
			free(map_copy);
			ft_error_map(info, "Map elements enclosed!");
		}
		j++;
	}
}

void	validate_map_access(t_game *info)
{
	char	**map_copy;
	int		i;

	validate_coor(info);
	map_copy = copy_map(info);
	if (!map_copy)
		ft_error_map(info, "Failed to copy map!");
	flood_fill(map_copy, info->map_info.player_x, info->map_info.player_y);
	i = 0;
	while (map_copy[i])
	{
		elements_locked(info, map_copy, i);
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}
