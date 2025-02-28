/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrade <andrade@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:24:41 by andrade           #+#    #+#             */
/*   Updated: 2025/02/28 17:19:41 by andrade          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	print_map(t_map *map_info)
{
	int	i;

	i = 0;
	while (map_info->grid[i])
	{
		printf("%s", map_info->grid[i]);
		i++;
	}
}

void	init_map(t_map *map_info, char *f_name)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(f_name, O_RDONLY);
	if (fd < 0)
		error_fd(fd);
	int height = 0;
	while ((line = get_next_line(fd)))
	{
		free(line);
		height++;
	}
	close(fd);
	map_info->height = height;
	map_info->grid = ft_calloc(map_info->height + 1, sizeof(char *));
	if (!map_info->grid)
		error_fd(fd);
	fd = open(f_name, O_RDONLY);
	if (fd < 0)
		error_fd(fd);
	while ((line = get_next_line(fd)) && i < map_info->height)
	{
		map_info->grid[i] = ft_strdup(line);
		free(line);
		i++;
	}
	map_info->grid[i] = NULL;
	close(fd);
	print_map(map_info);
}

