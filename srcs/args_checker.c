/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrade <andrade@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:30:32 by joaomart          #+#    #+#             */
/*   Updated: 2025/02/28 16:15:10 by andrade          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_args(int ac, char *f_name)
{
	check_ac(ac);
	check_filename(f_name);
	check_map_exists(f_name);
}

void	check_ac(int ac)
{
	if (ac > 2)
		error();
	else if (ac < 2)
		error();
}

void	check_filename(char *f_name)
{
	int	i;
	int	j;
	char	*type;

	i = ft_strlen(f_name) - 4;
	j = 0;
	type = ".ber";
	while (f_name[i])
	{
		if (f_name[i] == type[j])
		{
			i++;
			j++;
		}
		else
			error();
	}
}

void	check_map_exists(char *f_name)
{
	int	fd;

	fd = open(f_name, O_RDONLY);
	if (fd == -1)
		error();
}
