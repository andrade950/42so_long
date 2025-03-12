/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:12:37 by joaomart          #+#    #+#             */
/*   Updated: 2025/03/11 20:11:56 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_error(char *msg)
{
	ft_printf("Error - %s\n", msg);
	exit(EXIT_FAILURE);
}

void	ft_error_map(t_game *info, char *msg)
{
	ft_printf("Error - %s\n", msg);
	free_game(info);
	exit(EXIT_FAILURE);
}

void	ft_error_fd(int fd, char *msg)
{
	ft_printf("Error - %s\n", msg);
	close(fd);
	exit(EXIT_FAILURE);
}
