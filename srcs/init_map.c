/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:24:41 by joaomart          #+#    #+#             */
/*   Updated: 2025/03/11 20:11:03 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_map(t_game *info, char *f_name)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	info->map_info.height = map_height(info, f_name);
	info->map_info.grid = ft_calloc(info->map_info.height + 2, sizeof(char **));
	if (!info->map_info.grid)
		ft_error_map(info, "Alocacao do mapa falhou!");
	fd = open(f_name, O_RDONLY);
	if (fd < 0)
		ft_error_fd(fd, "Ficheiro nao abriu!");
	line = get_next_line(fd);
	while (line && i < info->map_info.height)
	{
		info->map_info.grid[i] = ft_strdup(line);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	info->map_info.grid[i] = NULL;
	close(fd);
}

void	init_elements(t_game *info)
{
	info->map_info.n_player = 0;
	info->map_info.n_collects = 0;
	info->map_info.n_enemy = 0;
	info->map_info.n_exit = 0;
	info->moves = 0;
	info->map_info.last_p_x = -1;
	info->map_info.last_p_y = -1;
	info->assets.player_frame = 0;
	info->assets.enemy_frame = 0;
	info->assets.collect_frame = 0;
	info->assets.exit_frame = 0;
}

void	print_map(t_game *info)
{
	int	i;

	i = 0;
	while (info->map_info.grid[i])
	{
		ft_printf("%s", info->map_info.grid[i]);
		i++;
	}
}
