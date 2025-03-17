/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:45:27 by joaomart          #+#    #+#             */
/*   Updated: 2025/03/17 15:40:36 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	map_height(t_game *info, char *f_name)
{
	int		fd;
	int		n_lines;
	char	*line;

	fd = open(f_name, O_RDONLY);
	if (fd < 0)
		ft_error_fd(fd, "File did not open!");
	n_lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		n_lines++;
		line = get_next_line(fd);
	}
	close(fd);
	if (n_lines == 0)
		ft_error("Invalid map height!");
	info->map_info.height = n_lines;
	return (n_lines);
}

void	validate_map_shape(t_game *info)
{
	int		i;
	size_t	f_line;

	if (!info->map_info.grid || !info->map_info.grid[0])
		ft_error_map(info, "Invalid map size!");
	f_line = ft_strlen(info->map_info.grid[0]);
	i = 1;
	while (info->map_info.grid[i])
	{
		if (ft_strlen(info->map_info.grid[i]) != f_line)
			ft_error_map(info, "The map is not rectangular!");
		i++;
	}
	info->map_info.width = f_line;
}

void	validate_map_elements(t_game *info)
{
	coor_maps(info);
	n_of_elements(info);
}

void	validate_map_walls(t_game *info)
{
	int	x;
	int	y;
	int	end_x;
	int	end_y;

	x = 0;
	y = 0;
	end_x = info->map_info.width - 2;
	end_y = info->map_info.height - 1;
	while (x <= end_x || y <= end_y)
	{
		if (info->map_info.grid[y][0] != '1' || info->map_info.grid[0][x] != '1'
				|| info->map_info.grid[end_y][x] != '1'
				|| info->map_info.grid[y][end_x] != '1')
			ft_error_map(info, "The map's wall is incomplete!");
		else if (y < end_y)
			y++;
		else if (x < end_x)
			x++;
		else
			break ;
	}
}

void	validate_map(t_game *info, char *f_name)
{
	map_height(info, f_name);
	validate_map_shape(info);
	validate_map_elements(info);
	validate_map_walls(info);
	validate_map_access(info);
}
