/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:45:27 by joaomart          #+#    #+#             */
/*   Updated: 2025/02/27 17:49:50 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* void	check_map(char *map)
{

} */

void	check_map_rect(char *map)
{
	int	fd;
	int i = 0;

	fd = open(map, O_RDONLY);
	while (get_next_line(fd))
	{
		i++;
	}
	ft_printf("%d", i);
}
