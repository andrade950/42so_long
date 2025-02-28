/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrade <andrade@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:56:38 by andrade           #+#    #+#             */
/*   Updated: 2025/02/28 17:14:21 by andrade          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	measure_lines(t_map *map_info, char *f_name)
{
	int		fd;
	int		n_lines;
	char	*line;

	fd = open(f_name, O_RDONLY);
	if (fd < 0)
		error_fd(fd);
	n_lines = 0;
	while ((line = get_next_line(fd)))
	{
		free(line);
		n_lines++;
	}
	close(fd);
	if (n_lines == 0)
		error();
	map_info->height = n_lines;
}

void	validate_map_shape(t_map *map_info)
{
	int	i;
	size_t	f_line;

	if (!map_info->grid || !map_info->grid[0])
		error();
	f_line = ft_strlen(map_info->grid[0]);
	i = 1;
	while (map_info->grid[i])
	{
		if (ft_strlen(map_info->grid[i]) != f_line)
			error();
		i++;
	}
	map_info->width = f_line;
}


