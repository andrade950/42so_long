/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrade <andrade@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:30:32 by joaomart          #+#    #+#             */
/*   Updated: 2025/03/14 10:27:16 by andrade          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	check_ac(int ac)
{
	if (ac > 2)
		ft_error("Too many arguments!");
	else if (ac < 2)
		ft_error("Too few arguments!");
}

void	check_filename(char *f_name)
{
	int		i;
	int		j;
	char	*type;

	i = ft_strlen(f_name) - 4;
	j = 0;
	type = ".ber";
	if (f_name[i - 1] == '/' || f_name[i - 1] == '\0')
		ft_error("Wrong file!");
	while (f_name[i])
	{
		if (f_name[i] == type[j])
		{
			i++;
			j++;
		}
		else
			ft_error("Wrong file name!");
	}
}

void	check_map_exists(char *f_name)
{
	int	fd;

	fd = open(f_name, O_RDONLY);
	if (fd < 0)
		ft_error("File does not exist!");
	close(fd);
}

void	check_args(int ac, char *f_name)
{
	check_ac(ac);
	check_filename(f_name);
	check_map_exists(f_name);
}
