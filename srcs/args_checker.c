/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:30:32 by joaomart          #+#    #+#             */
/*   Updated: 2025/03/05 20:02:06 by joaomart         ###   ########.fr       */
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
		error("Argumentos a mais!");
	else if (ac < 2)
		error("Argumentos a menos!");
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
		error("Ficheiro errado!");
	while (f_name[i])
	{
		if (f_name[i] == type[j])
		{
			i++;
			j++;
		}
		else
			error("Nome do ficheiro errado!");
	}
}

void	check_map_exists(char *f_name)
{
	int	fd;

	fd = open(f_name, O_RDONLY);
	if (fd < 0)
		error_fd(fd, "Ficheiro nao existe!");
}
