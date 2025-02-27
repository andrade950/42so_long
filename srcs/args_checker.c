/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:30:32 by joaomart          #+#    #+#             */
/*   Updated: 2025/02/27 17:38:29 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_args(int ac, char *str)
{
	check_ac(ac);
	check_filename(str);
	check_maps_exists(str);
}

void	check_ac(int ac)
{
	if (ac > 2)
		error();
	else if (ac < 2)
		error();
}

void	check_filename(char *str)
{
	int	i;
	int	j;
	char	*type;

	i = ft_strlen(str) - 4;
	j = 0;
	type = ".ber";
	while (str[i])
	{
		if (str[i] == type[j])
		{
			i++;
			j++;
		}
		else
			error();
	}
}

void	check_maps_exists(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		error();
}
