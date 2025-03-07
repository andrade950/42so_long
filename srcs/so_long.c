/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrade <andrade@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:32:51 by joaomart          #+#    #+#             */
/*   Updated: 2025/03/07 17:04:24 by andrade          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{
	t_game	info;

	check_args(ac, av[1]);
	init_elements(&info);
	init_map(&info, av[1]);
	validate_map(&info, av[1]);
	open_window(&info);
	print_map(&info);
}
