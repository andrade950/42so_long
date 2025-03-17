/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:24:41 by joaomart          #+#    #+#             */
/*   Updated: 2025/03/17 15:43:57 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_imgs(t_game *info)
{
	info->assets.player = NULL;
	info->assets.collects = NULL;
	info->assets.exit[0] = NULL;
	info->assets.exit[1] = NULL;
	info->assets.floor = NULL;
	info->assets.wall = NULL;
}

void	init_elements(t_game *info)
{
	info->map_info.n_player = 0;
	info->map_info.n_collects = 0;
	info->map_info.n_exit = 0;
	info->map_info.width = 0;
	info->map_info.height = 0;
	info->map_info.player_x = 0;
	info->map_info.player_y = 0;
	info->moves = 0;
	info->mlx = NULL;
	info->window = NULL;
	info->map_info.grid = NULL;
	init_imgs(info);
}

void	init_map(t_game *info, char *f_name)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	info->map_info.height = map_height(info, f_name);
	info->map_info.grid = ft_calloc(info->map_info.height + 1, sizeof(char *));
	if (!info->map_info.grid)
		ft_error_map(info, "Map allocation failed!");
	fd = open(f_name, O_RDONLY);
	if (fd < 0)
		ft_error_fd(fd, "File did not open!");
	line = get_next_line(fd);
	while (line && i < info->map_info.height)
	{
		if (!line)
			ft_error_map(info, "Error reading map line!");
		info->map_info.grid[i] = ft_strdup(line);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	info->map_info.grid[i] = NULL;
	close(fd);
}
