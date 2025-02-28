/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrade <andrade@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:12:37 by joaomart          #+#    #+#             */
/*   Updated: 2025/02/28 16:51:41 by andrade          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	error()
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	error_fd(int fd)
{
	ft_printf("Error\n");
	close(fd);
	exit(EXIT_FAILURE);
}
