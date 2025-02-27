/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:30:32 by joaomart          #+#    #+#             */
/*   Updated: 2025/02/26 21:37:04 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_ac(int ac)
{
	if (ac > 2)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	else if (ac < 2)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
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
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
	}
}
